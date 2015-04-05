#include "Lexer.h"


Lexer::Lexer() :
{
	m_init_vector = {
		0, //a
		0, //b
		0, //c
		0, //d
		1, //e
		3, //f
		5, //g
		0,
		11, //i
		0, 0,
		12, //l
		0,
		14, //n
		0,
		0, //p
		0, 
		17, //r
		23, //s
		26, //t
		0, 0, 0, 0, 0, 0
	};
	m_transition_table = {
		{},
		{ 'N', 0, &Lexer::B1d },
		{ 'D', 0, &Lexer::A2q },
		{ 'O', 0, &Lexer::B1d },
		{ 'R', 0, &Lexer::F1b },
		{ 'O', 0, &Lexer::B1d },
		{ 'T', 8, &Lexer::B1d },
		{ 'O', 0, &Lexer::E1a },
		{ 'S', 0, &Lexer::B1d },
		{ 'U', 0, &Lexer::B1d },
		{ 'B', 0, &Lexer::E1b },
		{ 'F', 0, &Lexer::A2r },
		{ 'E', 0, &Lexer::B1d },
		{ 'T', 0, &Lexer::F1a },
		{ 'E', 0, &Lexer::B1d },
		{ 'X', 0, &Lexer::B1d },
		{ 'T', 0, &Lexer::C1a },
		{ 'E', 0, &Lexer::B1d },
		{ 'T', 22, &Lexer::B1d },
		{ 'U', 0, &Lexer::B1d },
		{ 'R', 0, &Lexer::B1d },
		{ 'N', 0, &Lexer::A2s },
		{ 'M', 0, &Lexer::G1a },
		{ 'T', 0, &Lexer::B1d },
		{ 'E', 0, &Lexer::B1d },
		{ 'P', 0, &Lexer::A2t },
		{ 'O', 0, &Lexer::A2u }
		

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
void Lexer::F1()
{
	RSOS = state::F1;
}
void Lexer::F1a()
{
	RKL = lexeme_token_class::assignment;
	RSOS = state::F1;
}
void Lexer::F1b()
{
	RKL = lexeme_token_class::FOR;
	RSOS = state::F1;
}
void Lexer::F2()
{
	RSOS = state::F2;
}
void Lexer::F2a()
{
	RU = UTO + RZ;
	RSOS = state::F2;
}
void Lexer::F3()
{
	RSOS = state::F3;
}
void Lexer::F3a()
{
	RZ = (RZ + 1) * 26;
	RU += RZ;
	RSOS = state::F3;
}
void Lexer::G1()
{
	RSOS = state::G1;
}
void Lexer::G1a()
{
	RKL = lexeme_token_class::REM;
	RSOS = state::G1;
}
void Lexer::H1()
{
	RSOS = state::H1;
}
void Lexer::H1a()
{
	ROT = RZ;
	RSOS = state::H1;
}
void Lexer::H1b()
{
	addLexem();
	RSOS = state::H1;
}
void Lexer::H1c()
{
	DA1D();
	RSOS = state::H1;
}
void Lexer::H1d()
{
	DA2D();
	H1b();
	RSOS = state::H1;
}
void Lexer::H1e()
{
	DA3D();
	H1b();
	RSOS = state::H1;
}
void Lexer::H1f()
{
	DA1E();
	H1b();
	RSOS = state::H1;
}
void Lexer::M1()
{
	if (m_transition_table[ROB].symbol == RZ)
	{
		(this->*m_transition_table[ROB].method)();
	}
	else
	{
		ROB = m_transition_table[ROB].alternative;
	}
	if (ROB == 0)
	{
		error_method();
	}
	//"Остаться в состоянии М1" Где такое состояние?
}
void Lexer::M2()
{
	if (RZ!=5)
	{
		DA1D();
		B1b();
	}
	else
	{
		D3a();
	}
}
void Lexer::M3()
{
	if (RZ != 5)
	{
		DA2D();
		B1b();
	}
	else
	{
		D3();
	}
}
void Lexer::EXIT1()
{
	//"ВЫХОД1:    Загрузить КОНЕЦ МАРКЕР в РЕГИСТР КЛАССА" Что такое КОНЕЦ МАРКЕР?
	addLexem();
}
void Lexer::EXIT2()
{
	addLexem();
}
void Lexer::EXIT3()
{
	DA1D();
}
void Lexer::EXIT4()
{
	DA2D();
	EXIT2();
}
void Lexer::EXIT5()
{
	DA3D();
	EXIT2();
}
void Lexer::EXIT6()
{
	DA1E();
	EXIT2();
}
void Lexer::DA1D()
{
	RP = 0;
	calculateConstant();
}
void Lexer::DA1E()
{
	
}
void Lexer::DA2D()
{
	RP = -RS;
	calculateConstant();
}
void Lexer::DA3D()
{
	if (RZN <0)
	{
		RP = -RP;
	}
	RP -= RS;
	calculateConstant();
}
void Lexer::DA1LOOP()
{

}
void Lexer::error_method()
{

}
void Lexer::addLexem()
{

}

void start(std::string filename);