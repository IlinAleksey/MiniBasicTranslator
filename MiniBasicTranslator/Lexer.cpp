#include "Lexer.h"


Lexer::Lexer() :
TO(286, id{0,0}),
NTO(287)
{

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
	DA1e(tkn);
	A1a(tkn);
	RSOS = state::A1;
}