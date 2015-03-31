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