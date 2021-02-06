
void main(uniform float4x4 u_MVPMatrix,
          float4 a_Position, 
          float4 a_Color, 
          float4 out vPosition : POSITION,
          float4 out vColor : COLOR)
{
    vPosition = mul(a_Position, u_MVPMatrix);
    vColor = a_Color.bgra;
}