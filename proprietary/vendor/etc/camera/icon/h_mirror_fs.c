#version 300 es

precision mediump float;

in vec2 vTexCoor;
uniform sampler2D sTexture;
out vec4 uFragColor;
uniform float alpha;
uniform int direction;

void main()
{
    if(direction == 0) {
        if(vTexCoor.s < 0.5) {
            uFragColor = texture(sTexture, vec2(1.0-vTexCoor.s, vTexCoor.t));
        }
        else {
            uFragColor = texture(sTexture, vTexCoor);
        }
    }
    else if(direction == 90) {
        if(vTexCoor.t > 0.5) {
            uFragColor = texture(sTexture, vec2(vTexCoor.s, 1.0-vTexCoor.t));
        }
        else {
            uFragColor = texture(sTexture, vTexCoor);
        }
    }
    else if(direction == 180) {
        if(vTexCoor.s > 0.5) {
            uFragColor = texture(sTexture, vec2(1.0-vTexCoor.s, vTexCoor.t));
        }
        else {
            uFragColor = texture(sTexture, vTexCoor);
        }
    }
    else {
        if(vTexCoor.t < 0.5) {
            uFragColor = texture(sTexture, vec2(vTexCoor.s, 1.0-vTexCoor.t));
        }
        else {
            uFragColor = texture(sTexture, vTexCoor);
        }
    }
}
