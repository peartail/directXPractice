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

float4x4 gWm;
float4x4 gVm;
float4x4 gPm;

float4 gWLp;
float4 gWcp;

VS_OUTPUT vs_main(VS_INPUT i)
{
	VS_OUTPUT o;

	o.mp = mul(i.mp, gWm);

	float3 ld = o.mp.xyz - gWLp.xyz;
		ld = normalize(ld);

	float3 vdir = normalize(o.mp.xyz - gWLp.xyz);
		o.mvd = vdir;

	o.mp = mul(o.mp, gVm);
	o.mp = mul(o.mp, gPm);


	float3 wn = mul(i.mN, (float3x3)gWm);

		wn = normalize(wn);

	o.md = dot(-ld, wn);
	o.mr = reflect(ld, wn);

	o.mUV = i.mUV;

	return o;
}
