
float4 main(float4 vColor : COLOR, 
          float2 vTexcoord0 : TEXCOORD0, 
          uniform sampler2D uTexture0 : TEXUNIT0)
{
    /* Sample the current texture */
    return tex2D(uTexture0, vTexcoord0) * vColor;
}

