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
static std::vector<std::string> vecSTARSType = { "���", "����", "�����", "������", "��������" };
static std::vector<std::string> vecSSR_STARSType =
{
	"���_N ", "����_R", "�����_SR", "������_SSR", "�������_SP"
};