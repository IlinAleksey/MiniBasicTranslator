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

}
