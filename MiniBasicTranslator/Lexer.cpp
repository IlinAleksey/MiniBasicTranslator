#include "Lexer.h"
#include <fstream>
#include <string>

Lexer::Lexer()
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
	NTO = 278;
	UTL = new lexeme_token[100];
	NTL = 0;
}


Lexer::~Lexer()
{
	delete [] UTO;
	delete [] UTL;
}

void Lexer::A1b( )
{
	DA1D( );
	RSOS = state::A1_state;
}

void Lexer::A1a( )
{
	addLexem();
	RSOS = state::A1_state;
}

void Lexer::A1( )
{
	RSOS = state::A1_state;
}

void Lexer::A1c( )
{
	DA1D( );
	A1a( );
	RSOS = state::A1_state;
}

void Lexer::A1d( )
{
	DA3D( );
	A1a( );
	RSOS = state::A1_state;
}

void Lexer::A1e( )
{
	DA1E( );
	A1a( );
	RSOS = state::A1_state;
}

void Lexer::A2c( )
{
	DA1D( );
	RSOS = state::A2_state;
}

void Lexer::A2g( )
{
	addLexem();
	RSOS = state::A2_state;
}

void Lexer::A2a( )
{
	RKL = arithmetic_operation;
	RSOS = state::A2_state;
}

void Lexer::A2b( )
{
	addLexem();
	RSOS = state::A2_state;
}

void Lexer::A2( )
{
	RSOS = state::A2_state;
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
	RSOS = state::A2_state;
}

void Lexer::A2k( )
{
	addLexem();
	RSOS = state::A2_state;
}

void Lexer::A2h( )
{
	RKL = left_parenthesis;
	addLexem();
	RSOS = state::A2_state;
}

void Lexer::A2l( )
{
	DA1D( );
	A2k( );
	RSOS = state::A2_state;
}

void Lexer::A2m( )
{
	DA2D( );
	A2k( );
	RSOS = state::A2_state;
}

void Lexer::A2n( )
{
	DA3D( );
	A2k( );
	RSOS = state::A2_state;
}

void Lexer::A2o( )
{
	if (RZN != 1)
	{
		error_method();
	}
	else
	{
		A2b();
	}
}

void Lexer::A2p( )
{
	int new_relationship;
	switch (ROT)
	{
	case less:
		switch (RZN)
		{
		case equal:
			new_relationship = lessorequal;
			break;
		case more:
			new_relationship = notequal;
		default:
			new_relationship = -1;
			break;
		}
		break;
	case more:
		switch (RZN)
		{
		case equal:
			new_relationship = moreorequal;
			break;
		default:
			new_relationship = -1;
			break;
		}
		break;
	case equal:
		new_relationship = -1;
		break;
	default:
		new_relationship = -1;
		break;
	}
	if (new_relationship == -1)
	{
		error_method();
	}
	ROT = new_relationship;
	RSOS = state::A2_state;
}

void Lexer::A2q( )
{
	RKL = lexeme_token_class::END;
	RSOS = state::A2_state;
}

void Lexer::A2r( )
{
	RKL = lexeme_token_class::IF;
	RSOS = state::A2_state;
}

void Lexer::A2s( )
{
	RKL = lexeme_token_class::RETURN;
	RSOS = state::A2_state;
}

void Lexer::A2t( )
{
	RKL = lexeme_token_class::STEP;
	RSOS = state::A2_state;
}

void Lexer::A2u( )
{
	RKL = lexeme_token_class::TO;
	RSOS = state::A2_state;
}
void A3();
void Lexer::A3a()
{
	RZN = (RZN + 1) * 26;
	RZN += RU;
	addLexem();
	RSOS = state::A3_state;
}
void Lexer::A3b()
{
	RKL = right_parenthesis;
	addLexem();
	RSOS = state::A3_state;
}
void Lexer::A3c()
{
	addLexem();
	RSOS = state::A3_state;
}
void Lexer::A3d()
{
	DA1D();
	RSOS = state::A3_state;
}
void Lexer::A3e()
{
	DA2D();
	A3c();
	RSOS = state::A3_state;
}
void Lexer::A3f()
{
	DA3D();
	A3c();
	RSOS = state::A3_state;
}
void Lexer::A3g()
{
	DA1E();
	A3c();
	RSOS = state::A3_state;
}
void B1();
void Lexer::B1a()
{
	ROB = m_init_vector[RZN - 'a'];
	if (ROB == -1) error_method();   //Не уверен в необходимости ветки ELSE
	else
		RSOS = state::B1_state;
}
void Lexer::B1b()
{
	addLexem();
	RSOS = state::B1_state;
}
void Lexer::B1c()
{
	DA3D();
	RSOS = state::B1_state;
}
void Lexer::B1d()
{
	ROB++;
	RSOS = state::B1_state;
}
void Lexer::B1e()
{
	DA1E();
	B1b();
	RSOS = state::B1_state;
}
void C1();
void Lexer::C1a()
{
	RKL = end_of_loop;
	RSOS = state::C1_state;
}
void Lexer::С1b()
{
	//Нет такой функции
}
void Lexer::C2a()
{
	RKL = identifier;
	RSOS = state::C2_state;
}
void Lexer::C2b()
{
	addLexem();
	RSOS = state::C2_state;
}
void Lexer::C2d()
{
	RU = RZN;
	RSOS = state::C2_state;
}
void C2();
void D1();
void Lexer::D1a()
{
	RKL = identifier;
	RCH = RZN;
	RSOS = state::D1_state;
}
void Lexer::D1b()
{
	RCH *= 10;
	RCH += RZN;
	RSOS = state::D1_state;
}
void Lexer::D1c()
{
	addLexem();
	RSOS = state::D1_state;
}
void D2();
void Lexer::D2a()
{
	RS++;
	RCH *= 10;
	RCH += RZN;
	RSOS = state::D2_state;
}
void Lexer::D2b()
{
	RS = 1;
	RCH = RZN;
	RSOS = state::D2_state;

}
void Lexer::D2c()
{
	RS = 0;
	RSOS = state::D2_state;
}
void Lexer::D3()
{
	RSOS = state::D3_state;
}
void Lexer::D3a()
{
	RS = 0;
	RSOS = state::D3_state;
}
void Lexer::D4a( )
{
	switch (RZN)
	{
	case 1:
		RZN = 1;
	case 2:
		RZN = -1;
	default:
		error_method();
		break;
	}
	RSOS = state::D4_state;
}

void Lexer::D4( )
{

	RSOS = state::D4_state;
}

void Lexer::D5a( )
{
	RZN = 1;
	RSOS = state::D5_state;
}

void Lexer::D5b( )
{
	RP = RZN;
	RSOS = state::D5_state;
}

void Lexer::D5( )
{
	RSOS = state::D5_state;
}

void Lexer::D5c( )
{
	RP *= 10;
	RP += RZN;
	RSOS = state::D5_state;
}
void Lexer::D6()
{
	addLexem();
	RSOS = state::D6_state;
}
void Lexer::D6a()
{

	RSOS = state::D6_state;
}
void Lexer::E1()
{
	RSOS = state::E1_state;
}
void Lexer::E1a()
{
	RKL = lexeme_token_class::transfer;
	RSOS = state::E1_state;
}
void Lexer::E1b()
{
	RKL = lexeme_token_class::transfer_sub;
	RSOS = state::E1_state;
}
void Lexer::E2()
{
	RSOS = state::E2_state;
}
void Lexer::E2a()
{
	RKL = lexeme_token_class::label;
	RSOS = state::E2_state;
}
void Lexer::E2b()
{
	RSTR = RZN;
	RSOS = state::E2_state;
}
void Lexer::E2c()
{
	RSTR *= 10;
	RSTR += RZN;
	RSOS = state::E2_state;
}
void Lexer::F1()
{
	RSOS = state::F1_state;
}
void Lexer::F1a()
{
	RKL = lexeme_token_class::assignment;
	RSOS = state::F1_state;
}
void Lexer::F1b()
{
	RKL = lexeme_token_class::FOR;
	RSOS = state::F1_state;
}
void Lexer::F2()
{
	RSOS = state::F2_state;
}
void Lexer::F2a()
{
	RU = RZN;
	RSOS = state::F2_state;
}
void Lexer::F3()
{
	RSOS = state::F3_state;
}
void Lexer::F3a()
{
	RZN = (RZN + 1) * 26;
	RU += RZN;
	RSOS = state::F3_state;
}
void Lexer::G1()
{
	RSOS = state::G1_state;
}
void Lexer::G1a()
{
	RKL = lexeme_token_class::REM;
	RSOS = state::G1_state;
}
void Lexer::H1()
{
	RSOS = state::H1_state;
}
void Lexer::H1a()
{
	ROT = RZN;
	RSOS = state::H1_state;
}
void Lexer::H1b()
{
	addLexem();
	RSOS = state::H1_state;
}
void Lexer::H1c()
{
	DA1D();
	RSOS = state::H1_state;
}
void Lexer::H1d()
{
	DA2D();
	H1b();
	RSOS = state::H1_state;
}
void Lexer::H1e()
{
	DA3D();
	H1b();
	RSOS = state::H1_state;
}
void Lexer::H1f()
{
	DA1E();
	H1b();
	RSOS = state::H1_state;
}
void Lexer::M1()
{
	if (m_transition_table[ROB].symbol == RZN)
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
}
void Lexer::M2()
{
	if (RZN!=5)
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
	if (RZN != 5)
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
	RKL = lexeme_token_class::END_OF_FILE;
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
	int pos = UTS.find(RSTR);
	if (pos != -1)
	{
		error_method();
	}
	else
	{
		RZN = UTS.add(RSTR, NTL);
	}
}
void Lexer::DA2D()
{
	RP = -RS;
	calculateConstant();
}
void Lexer::DA3D()
{
	if (RZ <0)   //Сделал RZ а не RZN(Максим)
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
	UTL[NTL] = lexeme_token{ lexeme_token_class(RKL), RZN };
	NTL++;
}
void Lexer::start(std::string filename)
{
	std::ifstream infile(filename);
	std::string line;
	while (std::getline(infile, line))
	{

	}
}
void  Lexer::calculateConstant()
{

}