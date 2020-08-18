struct PS_Input
{
    float4 Pos;
    float2 UV;
    float3 Normal;
    float3 Binormal;
    float3 Tangent;
    float4 Color;
};

cbuffer VS_ConstantBuffer : register(b1)
{
    float4 _79_fLightDirection : packoffset(c0);
    float4 _79_fLightColor : packoffset(c1);
    float4 _79_fLightAmbient : packoffset(c2);
};

Texture2D<float4> g_colorTexture : register(t0);
SamplerState g_colorSampler : register(s0);
Texture2D<float4> g_normalTexture : register(t1);
SamplerState g_normalSampler : register(s1);

static float4 gl_FragCoord;
static float2 Input_UV;
static float3 Input_Normal;
static float3 Input_Binormal;
static float3 Input_Tangent;
static float4 Input_Color;
static float4 _entryPointOutput;

struct SPIRV_Cross_Input
{
    float2 Input_UV : TEXCOORD0;
    float3 Input_Normal : TEXCOORD1;
    float3 Input_Binormal : TEXCOORD2;
    float3 Input_Tangent : TEXCOORD3;
    float4 Input_Color : TEXCOORD4;
    float4 gl_FragCoord : SV_Position;
};

struct SPIRV_Cross_Output
{
    float4 _entryPointOutput : SV_Target0;
};

float4 _main(PS_Input Input)
{
    float4 Output = g_colorTexture.Sample(g_colorSampler, Input.UV) * Input.Color;
    float3 texNormal = (g_normalTexture.Sample(g_normalSampler, Input.UV).xyz - 0.5f.xxx) * 2.0f;
    float3 localNormal = normalize(mul(texNormal, float3x3(float3(Input.Tangent), float3(Input.Binormal), float3(Input.Normal))));
    float diffuse = max(dot(_79_fLightDirection.xyz, localNormal), 0.0f);
    float3 _99 = Output.xyz * ((_79_fLightColor.xyz * diffuse) + _79_fLightAmbient.xyz);
    Output = float4(_99.x, _99.y, _99.z, Output.w);
    if (Output.w == 0.0f)
    {
        discard;
    }
    return Output;
}

void frag_main()
{
    PS_Input Input;
    Input.Pos = gl_FragCoord;
    Input.UV = Input_UV;
    Input.Normal = Input_Normal;
    Input.Binormal = Input_Binormal;
    Input.Tangent = Input_Tangent;
    Input.Color = Input_Color;
    float4 _141 = _main(Input);
    _entryPointOutput = _141;
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    gl_FragCoord = stage_input.gl_FragCoord;
    Input_UV = stage_input.Input_UV;
    Input_Normal = stage_input.Input_Normal;
    Input_Binormal = stage_input.Input_Binormal;
    Input_Tangent = stage_input.Input_Tangent;
    Input_Color = stage_input.Input_Color;
    frag_main();
    SPIRV_Cross_Output stage_output;
    stage_output._entryPointOutput = _entryPointOutput;
    return stage_output;
}
