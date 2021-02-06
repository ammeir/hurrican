
void main(uniform float4x4 u_MVPMatrix,
          float4 a_Position, 
          float4 a_Color,
          float2 a_Texcoord0, 
          float4 out vPosition : POSITION,
          float4 out vColor : COLOR,
          float2 out vTexcoord0 : TEXCOORD0)
{
    
    vPosition = mul(a_Position, u_MVPMatrix);
    vColor = a_Color.bgra;
    vTexcoord0 = a_Texcoord0;
}

