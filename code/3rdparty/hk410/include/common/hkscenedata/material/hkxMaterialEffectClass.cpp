/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok).  Not for disclosure or distribution without Havok's
 * prior written consent.This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2006 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */

// WARNING: THIS FILE IS GENERATED. EDITS WILL BE LOST.
// Generated from 'hkscenedata/material/hkxMaterialEffect.h'

#include <hkscenedata/hkSceneData.h>
#include <hkbase/class/hkClass.h>
#include <hkbase/class/hkInternalClassMember.h>
#include <hkscenedata/material/hkxMaterialEffect.h>


//
// Enum hkxMaterialEffect::EffectType
//
static const hkInternalClassEnumItem hkxMaterialEffectEffectTypeEnumItems[] =
{
	{0, "EFFECT_TYPE_INVALID"},
	{1, "EFFECT_TYPE_UNKNOWN"},
	{2, "EFFECT_TYPE_HLSL_FX"},
	{3, "EFFECT_TYPE_CG_FX"},
	{4, "EFFECT_TYPE_MAX_ID"},
};
static const hkInternalClassEnum hkxMaterialEffectEnums[] = {
	{"EffectType", hkxMaterialEffectEffectTypeEnumItems, 5 }
};
extern const hkClassEnum* hkxMaterialEffectEffectTypeEnum = reinterpret_cast<const hkClassEnum*>(&hkxMaterialEffectEnums[0]);

//
// Class hkxMaterialEffect
//
static const hkInternalClassMember hkxMaterialEffectClass_Members[] =
{
	{ "name", HK_NULL, HK_NULL, hkClassMember::TYPE_CSTRING, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(hkxMaterialEffect,m_name) },
	{ "type", HK_NULL, hkxMaterialEffectEffectTypeEnum, hkClassMember::TYPE_ENUM, hkClassMember::TYPE_VOID, 0, hkClassMember::ENUM_8, HK_OFFSET_OF(hkxMaterialEffect,m_type) },
	{ "data", HK_NULL, HK_NULL, hkClassMember::TYPE_SIMPLEARRAY, hkClassMember::TYPE_UINT8, 0, 0, HK_OFFSET_OF(hkxMaterialEffect,m_data) }
};
extern const hkClass hkxMaterialEffectClass;
const hkClass hkxMaterialEffectClass(
	"hkxMaterialEffect",
	HK_NULL, // parent
	sizeof(hkxMaterialEffect),
	HK_NULL,
	0, // interfaces
	reinterpret_cast<const hkClassEnum*>(hkxMaterialEffectEnums),
	1, // enums
	reinterpret_cast<const hkClassMember*>(hkxMaterialEffectClass_Members),
	int(sizeof(hkxMaterialEffectClass_Members)/sizeof(hkInternalClassMember)),
	HK_NULL // defaults
	);

/*
* Havok SDK - PUBLIC RELEASE, BUILD(#20060902)
*
* Confidential Information of Havok.  (C) Copyright 1999-2006 
* Telekinesys Research Limited t/a Havok. All Rights Reserved. The Havok
* Logo, and the Havok buzzsaw logo are trademarks of Havok.  Title, ownership
* rights, and intellectual property rights in the Havok software remain in
* Havok and/or its suppliers.
*
* Use of this software for evaluation purposes is subject to and indicates 
* acceptance of the End User licence Agreement for this product. A copy of 
* the license is included with this software and is also available from salesteam@havok.com.
*
*/