#include "Lexer.h"


Lexer::Lexer() :
TO(286, id{0,0}),
NTO(287)
{
	m_init_vector = {
		-1, //a
		-1, //b
		-1, //c
		-1, //d
		1, //e
		3, //f
		5, //g
		-1,
		11, //i
		-1, -1,
		12, //l
		-1,
		14, //n
		-1,
		-1, //p
		-1, 
		17, //r
		23, //s
		26, //t
		-1, -1, -1, -1, -1, -1
	};
	m_transition_table = {
		{ 'N', -1, &Lexer::B1d },
		{ 'D', -1, &Lexer::A2q },
		{ 'O', -1, &Lexer::B1d },
		{ 'R', -1, &Lexer::F1b },
		{ 'O', -1, &Lexer::B1d },
		{ 'T', 7, &Lexer::B1d },
		{ 'O', -1, &Lexer::E1a },
		{ 'S', -1, &Lexer::B1d },
		{ 'U', -1, &Lexer::B1d },
		{ 'B', -1, &Lexer::E1b },
		{ 'F', -1, &Lexer::A2r },
		{ 'E', -1, &Lexer::B1d },
		{ 'T', -1, &Lexer::F1a },
		{ 'E', -1, &Lexer::B1d },
		{ 'X', -1, &Lexer::B1d },
		{ 'T', -1, &Lexer::C1a },
		{ 'E', -1, &Lexer::B1d },
		{ 'T', 21, &Lexer::B1d },
		{ 'U', -1, &Lexer::B1d },
		{ 'R', -1, &Lexer::B1d },
		{ 'N', -1, &Lexer::A2s },
		{ 'M', -1, &Lexer::G1a },
		{ 'T', -1, &Lexer::B1d },
		{ 'E', -1, &Lexer::B1d },
		{ 'P', -1, &Lexer::A2t },
		{ 'O', -1, &Lexer::A2u }
		

	};
}


Lexer::~Lexer()
{
}

void Lexer::A1(transliterator_token tkn)
{
	DA1D(tkn);
	RSOS = state::A1;
}

void Lexer::A1a(transliterator_token tkn)
{
	addLexem();
	RSOS = state::A1;
}

void Lexer::A1(transliterator_token tkn)
{
	RSOS = state::A1;
}

void Lexer::A1c(transliterator_token tkn)
{
	DA1D(tkn);
	A1a(tkn);
	RSOS = state::A1;
}

void Lexer::A1d(transliterator_token tkn)
{
	DA3D(tkn);
	A1a(tkn);
	RSOS = state::A1;
}

void Lexer::A1e(transliterator_token tkn)
{
	DA1E(tkn);
	A1a(tkn);
	RSOS = state::A1;
}

void Lexer::D4a(transliterator_token tkn)
{
	switch (tkn.m_value)
	{
	case 1:
		RZ = 1;
	case 2:
		RZ = -1;
	default:
		error_method();
		break;
	}
	RSOS = state::D4;
}

void Lexer::D4(transliterator_token tkn)
{
	
	RSOS = state::D4;
}

void Lexer::D5a(transliterator_token tkn)
{
	RZ = 1;
	RSOS = state::D5;
}

void Lexer::D5b(transliterator_token tkn)
{
	RP = tkn.m_value;
	RSOS = state::D5;
}

void Lexer::D5(transliterator_token tkn)
{

	RSOS = state::D5;
}

void Lexer::D5c(transliterator_token tkn)
{
	RP*= 10;
	RP += tkn.m_value;
	RSOS = state::D5;
}
