void main(void)
{
    vec2 uv = gl_fragCoord.xy / iResolution.xy;
    vec2 texel = 1. / iResolution.xy;
    
    float step_y = texel.y;
    vec2 s  = vec2(0.0, -step_y);
    vec2 n  = vec2(0.0, step_y);
    
    vec4 im_n =  texture(texture, uv+n);
    vec4 im =    texture(texture, uv);
    vec4 im_s =  texture(texture, uv+s);
    
    float len_n = length(im_n);
    float len = length(im);
    float len_s = length(im_s);
    
    if(int(mod(float(iFrame) + gl_fragCoord.y, 2.0)) == 0) {
        if ((len_s > len)) {
            im = im_s;
        }
    } else {
        if ((len_n < len)) {
            im = im_n;
        }
    }
    
    // initialize with image
    if(iFrame<10) {
        gl_fragColor = texture(iChannel1, uv);
    } else {
        gl_fragColor = im;
    }
    
}
