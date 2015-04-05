#include "Lexer.h"


Lexer::Lexer() :
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
	UTO = new id[500];
	NTO = &UTO[278];
	UTL = new lexeme_token[100];
	NTL = UTL;
}


Lexer::~Lexer()
{
	delete [] UTO;
	delete [] UTL;
}

void Lexer::A1b( )
{
	DA1D( );
	RSOS = state::A1;
}

void Lexer::A1a( )
{
	addLexem();
	RSOS = state::A1;
}

void Lexer::A1( )
{
	RSOS = state::A1;
}

void Lexer::A1c( )
{
	DA1D( );
	A1a( );
	RSOS = state::A1;
}

void Lexer::A1d( )
{
	DA3D( );
	A1a( );
	RSOS = state::A1;
}

void Lexer::A1e( )
{
	DA1E( );
	A1a( );
	RSOS = state::A1;
}

void Lexer::A2c( )
{
	DA1D( );
	RSOS = state::A2;
}

void Lexer::A2g( )
{
	addLexem();
	RSOS = state::A2;
}

void Lexer::A2a( )
{
	RKL = arithmetic_operation;
	RSOS = state::A2;
}

void Lexer::A2b( )
{
	addLexem();
	RSOS = state::A2;
}

void Lexer::A2( )
{
	RSOS = state::A2;
}

void Lexer::A2d( )
{
	DA2D( );
	A2g( );
}

void Lexer::A2e( )
{
	DA3D( );
	A2g( );
}

void Lexer::A2f( )
{
	DA1E( );
	A2g( );
}

void Lexer::A2j( )
{
	DA1E( );
	RSOS = state::A2;
}

void Lexer::A2k( )
{
	addLexem();
	RSOS = state::A2;
}

void Lexer::A2h( )
{
	RKL = left_parenthesis;
	addLexem();
	RSOS = state::A2;
}

void Lexer::A2l( )
{
	DA1D( );
	A2k( );
	RSOS = state::A2;
}

void Lexer::A2m( )
{
	DA2D( );
	A2k( );
	RSOS = state::A2;
}

void Lexer::A2n( )
{
	DA3D( );
	A2k( );
	RSOS = state::A2;
}

void Lexer::A2o( )
{
		//нужно доделать!!
}

void Lexer::A2p( )
{
	int nw; //что это
	switch (ROT)
	{
	case less:
		switch (c.value) //теперь c какое-то
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

void Lexer::A2g( )
{
	RKL = lexeme_token_class::END;
	RSOS = state::A2;
}

void Lexer::A2r( )
{
	RKL = lexeme_token_class::IF;
	RSOS = state::A2;
}

void Lexer::A2s( )
{
	RKL = lexeme_token_class::RETURN;
	RSOS = state::A2;
}

void Lexer::A2t( )
{
	RKL = lexeme_token_class::STEP;
	RSOS = state::A2;
}

void Lexer::A2u( )
{
	RKL = lexeme_token_class::TO;
	RSOS = state::A2;
}
void A3();
void A3a();
void A3b();
void A3c();
void A3d();
void A3e();
void A3f();
void A3g();
void B1();
void B1a();
void B1b();
void B1c();
void B1d();
void B1e();
void C1();
void C1a();
void С1b();
void C2a();
void C2b();
void C2d();
void C2();
void D1();
void D1a();
void D1b();
void D1c();
void D2();
void D2a();
void D2b();
void D2c();
void D3();
void D3a();
void Lexer::D4a( )
{
	switch (RZ)
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

void Lexer::D4( )
{

	RSOS = state::D4;
}

void Lexer::D5a( )
{
	RZ = 1;
	RSOS = state::D5;
}

void Lexer::D5b( )
{
	RP = RZ;
	RSOS = state::D5;
}

void Lexer::D5( )
{
	RSOS = state::D5;
}

void Lexer::D5c( )
{
	RP *= 10;
	RP += RZ;
	RSOS = state::D5;
}
void Lexer::D6()
{
	addLexem();
	RSOS = state::D6;
}
void Lexer::D6a()
{

	RSOS = state::D6;
}
void Lexer::E1()
{
	RSOS = state::E1;
}
void Lexer::E1a()
{
	RKL = lexeme_token_class::transfer;
	RSOS = state::E1;
}
void Lexer::E1b()
{
	RKL = lexeme_token_class::transfer_sub;
	RSOS = state::E1;
}
void Lexer::E2()
{
	RSOS = state::E2;
}
void Lexer::E2a()
{
	//Загрузить СТРОКУ в РЕГИСТР КЛАССА
	//Что такое СТРОКА?
}
void Lexer::E2b()
{
	RSTR = RZ;
	RSOS = state::E2;
}
void Lexer::E2c()
{
	RSTR *= 10;
	RSTR += RZ;
	RSOS = state::E2;
}
void F1();
void F1a();
void F1b();
void F2();
void F2a();
void F2b();
void F3();
void F3a();
void G1();
void G1a();
void H1();
void H1a();
void H1b();
void H1c();
void H1d();
void H1e();
void H1f();
void M1();
void M2();
void M3();
void H1a();
void EXIT1();
void EXIT2();
void EXIT3();
void EXIT4();
void EXIT5();
void EXIT6();
void DA1D();
void DA1E();
void DA2D();
void DA3D();
void DA1LOOP();
void error_method();
void addLexem();

void start(std::string filename);