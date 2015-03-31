#include "Lexer.h"


Lexer::Lexer() :
TO(286, id{0,0}),
NTO(287)
{

}


Lexer::~Lexer()
{
}

void Lexer::A1b(transliterator_token tkn)
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

void Lexer::A2c(transliterator_token tkn)
{
	DA1D(tkn);
	RSOS = state::A2;
}

void Lexer::A2g(transliterator_token tkn)
{
	addLexem();
	RSOS = state::A2;
}

void Lexer::A2a(transliterator_token tkn)
{
	RKL = arithmetic_operation;
	RSOS = state::A2;
}

void Lexer::A2b(transliterator_token tkn)
{
	addLexem();
	RSOS = state::A2;
}

void Lexer::A2(transliterator_token tkn)
{
	RSOS = state::A2;
}

void Lexer::A2d(transliterator_token tkn)
{
	DA2D(tkn);
	A2g(tkn);
}

void Lexer::A2e(transliterator_token tkn)
{
	DA3D(tkn);
	A2g(tkn);
}

void Lexer::A2f(transliterator_token tkn)
{
	DA1E(tkn);
	A2g(tkn);
}

void Lexer::A2j(transliterator_token tkn)
{
	DA1E(tkn);
	RSOS = state::A2;
}

void Lexer::A2k(transliterator_token tkn)
{
	addLexem();
	RSOS = state::A2;
}

void Lexer::A2h(transliterator_token tkn)
{
	RKL = left_parenthesis;
	addLexem();
	RSOS = state::A2;
}

void Lexer::A2l(transliterator_token tkn)
{
	DA1D(tkn);
	A2k(tkn);
	RSOS = state::A2;
}

void Lexer::A2m(transliterator_token tkn)
{
	DA2D(tkn);
	A2k(tkn);
	RSOS = state::A2;
}

void Lexer::A2n(transliterator_token tkn)
{
	DA3D(tkn);
	A2k(tkn);
	RSOS = state::A2;
}

void Lexer::A2o(transliterator_token tkn)
{
		//нужно доделать!!
}

void Lexer::A2p(transliterator_token tkn)
{
	int nw;
	switch (ROT)
	{
	case less:
		switch (c.value)
		{
		case equal:
			nw = lessorequal;
			break;
		case more:
			nw = notequal;
		default:
			nw = -1;
			break;
		}
		break;
	case more:
		switch (c.value)
		{
		case equal:
			nw = moreorequal;
			break;
		default:
			nw = -1;
			break;
		}
		break;
	case equal:
		nw = -1;
		break;
	default:
		nw = -1;
		break;
	}
	if (nw == -1)
	{
		error_method();
	}
	ROT = nw;
	RSOS = state::A2;
}

void Lexer::A2g(transliterator_token tkn)
{
	RKL = END;
	RSOS = state::A2;
}

void Lexer::A2r(transliterator_token tkn)
{
	RKL = IF;
	RSOS = state::A2;
}

void Lexer::A2s(transliterator_token tkn)
{
	RKL = RETURN;
	RSOS = state::A2;
}

void Lexer::A2t(transliterator_token tkn)
{
	RKL = STEP;
	RSOS = state::A2;
}

void Lexer::A2u(transliterator_token tkn)
{
	RKL = lexeme_token_class::TO;
	RSOS = state::A2;
}