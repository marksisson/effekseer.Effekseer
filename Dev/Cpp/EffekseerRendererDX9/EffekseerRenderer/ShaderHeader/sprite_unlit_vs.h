#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//   fxc /Zpc /Tvs_3_0 /Emain /Fh ShaderHeader/sprite_unlit_vs.h
//    Shader/sprite_unlit_vs.fx
//
//
// Parameters:
//
//   float4x4 _39_mCameraProj;
//   float4 _39_mUVInversed;
//
//
// Registers:
//
//   Name            Reg   Size
//   --------------- ----- ----
//   _39_mCameraProj c4       4
//   _39_mUVInversed c8       1
//

    vs_3_0
    dcl_texcoord v0
    dcl_texcoord1 v1
    dcl_texcoord2 v2
    dcl_texcoord o0
    dcl_texcoord1 o1.xy
    dcl_texcoord2 o2
    dcl_position o3
    mad o1.y, c8.y, v2.y, c8.x
    mov o0, v1
    mov o1.x, v2.x
    mul r0, c5, v0.y
    mad r0, c4, v0.x, r0
    mad r0, c6, v0.z, r0
    add r0, r0, c7
    mov o2, r0
    mov o3, r0

// approximately 9 instruction slots used
#endif

const BYTE g_vs30_main[] =
{
      0,   3, 254, 255, 254, 255, 
     48,   0,  67,  84,  65,  66, 
     28,   0,   0,   0, 139,   0, 
      0,   0,   0,   3, 254, 255, 
      2,   0,   0,   0,  28,   0, 
      0,   0,  16,   1,   0,   0, 
    132,   0,   0,   0,  68,   0, 
      0,   0,   2,   0,   4,   0, 
      4,   0,  18,   0,  84,   0, 
      0,   0,   0,   0,   0,   0, 
    100,   0,   0,   0,   2,   0, 
      8,   0,   1,   0,  34,   0, 
    116,   0,   0,   0,   0,   0, 
      0,   0,  95,  51,  57,  95, 
    109,  67,  97, 109, 101, 114, 
     97,  80, 114, 111, 106,   0, 
      3,   0,   3,   0,   4,   0, 
      4,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  95,  51, 
     57,  95, 109,  85,  86,  73, 
    110, 118, 101, 114, 115, 101, 
    100,   0,   1,   0,   3,   0, 
      1,   0,   4,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
    118, 115,  95,  51,  95,  48, 
      0,  77, 105,  99, 114, 111, 
    115, 111, 102, 116,  32,  40, 
     82,  41,  32,  72,  76,  83, 
     76,  32,  83, 104,  97, 100, 
    101, 114,  32,  67, 111, 109, 
    112, 105, 108, 101, 114,  32, 
     57,  46,  50,  57,  46,  57, 
     53,  50,  46,  51,  49,  49, 
     49,   0,  31,   0,   0,   2, 
      5,   0,   0, 128,   0,   0, 
     15, 144,  31,   0,   0,   2, 
      5,   0,   1, 128,   1,   0, 
     15, 144,  31,   0,   0,   2, 
      5,   0,   2, 128,   2,   0, 
     15, 144,  31,   0,   0,   2, 
      5,   0,   0, 128,   0,   0, 
     15, 224,  31,   0,   0,   2, 
      5,   0,   1, 128,   1,   0, 
      3, 224,  31,   0,   0,   2, 
      5,   0,   2, 128,   2,   0, 
     15, 224,  31,   0,   0,   2, 
      0,   0,   0, 128,   3,   0, 
     15, 224,   4,   0,   0,   4, 
      1,   0,   2, 224,   8,   0, 
     85, 160,   2,   0,  85, 144, 
      8,   0,   0, 160,   1,   0, 
      0,   2,   0,   0,  15, 224, 
      1,   0, 228, 144,   1,   0, 
      0,   2,   1,   0,   1, 224, 
      2,   0,   0, 144,   5,   0, 
      0,   3,   0,   0,  15, 128, 
      5,   0, 228, 160,   0,   0, 
     85, 144,   4,   0,   0,   4, 
      0,   0,  15, 128,   4,   0, 
    228, 160,   0,   0,   0, 144, 
      0,   0, 228, 128,   4,   0, 
      0,   4,   0,   0,  15, 128, 
      6,   0, 228, 160,   0,   0, 
    170, 144,   0,   0, 228, 128, 
      2,   0,   0,   3,   0,   0, 
     15, 128,   0,   0, 228, 128, 
      7,   0, 228, 160,   1,   0, 
      0,   2,   2,   0,  15, 224, 
      0,   0, 228, 128,   1,   0, 
      0,   2,   3,   0,  15, 224, 
      0,   0, 228, 128, 255, 255, 
      0,   0
};
