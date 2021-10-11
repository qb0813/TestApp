#pragma once

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