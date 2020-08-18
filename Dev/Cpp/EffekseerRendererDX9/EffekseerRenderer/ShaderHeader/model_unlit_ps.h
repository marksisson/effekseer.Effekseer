#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//   fxc /Zpc /Tps_3_0 /Emain /Fh ShaderHeader/model_unlit_ps.h
//    Shader/model_unlit_ps.fx
//
//
// Parameters:
//
//   sampler2D Sampler_g_colorSampler;
//
//
// Registers:
//
//   Name                   Reg   Size
//   ---------------------- ----- ----
//   Sampler_g_colorSampler s0       1
//

    ps_3_0
    def c0, -1, -0, 0, 0
    dcl_texcoord v0.xy
    dcl_texcoord1 v1
    dcl_2d s0
    texld r0, v0, s0
    mul r0, r0, v1
    cmp r1, -r0_abs.w, c0.x, c0.y
    texkill r1
    mov oC0, r0

// approximately 5 instruction slots used (1 texture, 4 arithmetic)
#endif

const BYTE g_ps30_main[] =
{
      0,   3, 255, 255, 254, 255, 
     37,   0,  67,  84,  65,  66, 
     28,   0,   0,   0,  95,   0, 
      0,   0,   0,   3, 255, 255, 
      1,   0,   0,   0,  28,   0, 
      0,   0,  16,   1,   0,   0, 
     88,   0,   0,   0,  48,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   2,   0,  72,   0, 
      0,   0,   0,   0,   0,   0, 
     83,  97, 109, 112, 108, 101, 
    114,  95, 103,  95,  99, 111, 
    108, 111, 114,  83,  97, 109, 
    112, 108, 101, 114,   0, 171, 
      4,   0,  12,   0,   1,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 112, 115, 
     95,  51,  95,  48,   0,  77, 
    105,  99, 114, 111, 115, 111, 
    102, 116,  32,  40,  82,  41, 
     32,  72,  76,  83,  76,  32, 
     83, 104,  97, 100, 101, 114, 
     32,  67, 111, 109, 112, 105, 
    108, 101, 114,  32,  57,  46, 
     50,  57,  46,  57,  53,  50, 
     46,  51,  49,  49,  49,   0, 
     81,   0,   0,   5,   0,   0, 
     15, 160,   0,   0, 128, 191, 
      0,   0,   0, 128,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     31,   0,   0,   2,   5,   0, 
      0, 128,   0,   0,   3, 144, 
     31,   0,   0,   2,   5,   0, 
      1, 128,   1,   0,  15, 144, 
     31,   0,   0,   2,   0,   0, 
      0, 144,   0,   8,  15, 160, 
     66,   0,   0,   3,   0,   0, 
     15, 128,   0,   0, 228, 144, 
      0,   8, 228, 160,   5,   0, 
      0,   3,   0,   0,  15, 128, 
      0,   0, 228, 128,   1,   0, 
    228, 144,  88,   0,   0,   4, 
      1,   0,  15, 128,   0,   0, 
    255, 140,   0,   0,   0, 160, 
      0,   0,  85, 160,  65,   0, 
      0,   1,   1,   0,  15, 128, 
      1,   0,   0,   2,   0,   8, 
     15, 128,   0,   0, 228, 128, 
    255, 255,   0,   0
};
