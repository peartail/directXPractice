//**************************************************************//
//  Effect File exported by RenderMonkey 1.6
//
//  - Although many improvements were made to RenderMonkey FX  
//    file export, there are still situations that may cause   
//    compilation problems once the file is exported, such as  
//    occasional naming conflicts for methods, since FX format 
//    does not support any notions of name spaces. You need to 
//    try to create workspaces in such a way as to minimize    
//    potential naming conflicts on export.                    
//    
//  - Note that to minimize resulting name collisions in the FX 
//    file, RenderMonkey will mangle names for passes, shaders  
//    and function names as necessary to reduce name conflicts. 
//**************************************************************//

//--------------------------------------------------------------//
// Lighting
//--------------------------------------------------------------//
//--------------------------------------------------------------//
// Pass 0
//--------------------------------------------------------------//
//string Lighting_Pass_0_Model : ModelData = "C:\\Program Files (x86)\\AMD\\RenderMonkey 1.82\\Examples\\Media\\Models\\Sphere.3ds";

struct VS_INPUT
{
   float4 mp : POSITION;
   float3 mN : NORMAL;
   float2 mUV : TEXCOORD0;
};

struct VS_OUTPUT
{
   float4 mp : POSITION;
   float2 mUV : TEXCOORD0;
   float3 md : TEXCOORD1;
   float3 mvd : TEXCOORD2;
   float3 mr : TEXCOORD3;
};

float4x4 gWm : World;
float4x4 gVm : View;
float4x4 gPm : Projection;

float4 gWLp
<
   string UIName = "gWLp";
   string UIWidget = "Direction";
   bool UIVisible =  false;
   float4 UIMin = float4( -10.00, -10.00, -10.00, -10.00 );
   float4 UIMax = float4( 10.00, 10.00, 10.00, 10.00 );
   bool Normalize =  false;
> = float4( 500.00, 500.00, 500.00, 1.00 );
float4 gWcp;

VS_OUTPUT Lighting_Pass_0_Vertex_Shader_vs_main(VS_INPUT i)
{
   VS_OUTPUT o;
   
   o.mp = mul(i.mp,gWm);
   
   float3 ld = o.mp.xyz - gWLp.xyz;
   ld = normalize(ld);
   
   float3 vdir = normalize(o.mp.xyz-gWLp.xyz);
   o.mvd = vdir;
   
   o.mp = mul(o.mp,gVm);
   o.mp = mul(o.mp,gPm);
   
   
   float3 wn = mul(i.mN,(float3x3)gWm);
   
   wn = normalize(wn);
   
   o.md = dot(-ld,wn);
   o.mr = reflect(ld,wn);
   
   o.mUV = i.mUV;
   
   return o;
}


float SpSize
<
   string UIName = "SpSize";
   string UIWidget = "Numeric";
   bool UIVisible =  false;
   float UIMin = -1.00;
   float UIMax = 1.00;
> = float( 20.00 );

struct PS_INPUT
{
   float2 mUV : TEXCOORD0;
   float3 md : TEXCOORD1;
   float3 mvd : TEXCOORD2;
   float3 mr : TEXCOORD3;
};

texture DiffuseMap_Tex
<
   string ResourceName = "Fieldstone.tga";
>;

sampler2D DSp = sampler_state
{
   Texture = (DiffuseMap_Tex);
};

texture SpecularMap_Tex
<
   string ResourceName = "fieldstone_SM.tga";
>;

sampler2D SSp = sampler_state
{
   Texture = (SpecularMap_Tex);
};

float3 gLightColor
<
   string UIName = "gLightColor";
   string UIWidget = "Numeric";
   bool UIVisible =  false;
   float UIMin = -1.00;
   float UIMax = 1.00;
> = float3( 0.70, 0.70, 1.00 );

float4 Lighting_Pass_0_Pixel_Shader_ps_main(PS_INPUT i) : COLOR0
{   
   float4 albedo = tex2D(DSp,i.mUV);
   
   float3 dif = gLightColor*albedo.rgb*saturate(i.md);
   
   float3 refl = normalize(i.mr);
   float3 vdir = normalize(i.mvd);
   
   float3 specular = 0;
   if(dif.x > 0)
   {
      specular = saturate(dot(refl,-vdir));
      specular = pow(specular,SpSize);
      float4 spIntens = tex2D(SSp,i.mUV);
      specular *= spIntens.rgb * gLightColor;
   }
   
   float3 ambient = float3(0.1f,0.1f,0.1f) * albedo;
   
   return float4(ambient + dif + specular,1);
   
}




//--------------------------------------------------------------//
// Technique Section for Lighting
//--------------------------------------------------------------//
technique Lighting
{
   pass Pass_0
   {
      VertexShader = compile vs_2_0 Lighting_Pass_0_Vertex_Shader_vs_main();
      PixelShader = compile ps_2_0 Lighting_Pass_0_Pixel_Shader_ps_main();
   }

}

