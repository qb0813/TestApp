#pragma once
#ifndef _DIRTEMPLATE_H
#define _DIRTEMPLATE_H
#include <map>

enum class E_TemplateType : int
{
	Begin = 0,
	SSR,
	STARS,
	SSR_STARS,
	End
};

static std::vector<std::string> vecSSRType = { "N", "R", "SR", "SSR", "SP" };
static std::vector<std::string> vecSTARSType = { "¡ï¡ï", "¡ï¡ï¡ï", "¡ï¡ï¡ï¡ï", "¡ï¡ï¡ï¡ï¡ï", "¡ï¡ï¡ï¡ï¡ï¡ï¡ï" };
static std::vector<std::string> vecSSR_STARSType =
{
	"¡ï¡ï_N ", "¡ï¡ï¡ï_R", "¡ï¡ï¡ï¡ï_SR", "¡ï¡ï¡ï¡ï¡ï_SSR", "¡ï¡ï¡ï¡ï¡ï¡ï_SP"
};


static std::map<std::string, E_TemplateType> mapTemplateType =
{
	{"SSR",			E_TemplateType::SSR},
	{"STARS",		E_TemplateType::STARS},
	{"SSR_STARS",   E_TemplateType::SSR_STARS}
};

#endif