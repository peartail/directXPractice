struct PS_INPUT
{
	float2 mUV : TEXCOORD0;
	float3 md : TEXCOORD1;
	float3 mvd : TEXCOORD2;
	float3 mr : TEXCOORD3;
};

float SpSize;

//sampler2D DSp;
//sampler2D SSp;

float3 gLightColor;

float4 ps_main(PS_INPUT i) : COLOR0
{
	/*float4 albedo = tex2D(DSp, i.mUV);

	float3 dif = gLightColor*albedo.rgb*saturate(i.md);

	float3 refl = normalize(i.mr);
	float3 vdir = normalize(i.mvd);

	float3 specular = 0;
	if (dif.x > 0)
	{
		specular = saturate(dot(refl, -vdir));
		specular = pow(specular, SpSize);
		float4 spIntens = tex2D(SSp, i.mUV);
			specular *= spIntens.rgb * gLightColor;
	}

	float3 ambient = float3(0.1f, 0.1f, 0.1f) * albedo;

		return float4(ambient + dif + specular, 1);
	*/
	return float4(1, 1, 1, 1);
}



