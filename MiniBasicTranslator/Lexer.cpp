#include "Lexer.h"
#include <fstream>
#include <string>
#include <math.h>
#include <ctype.h>
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
	UTO = new float[500];
	NTO = 278;
	UTL = new lexeme_token[100];
	NTL = 0;
	RSOS = &Lexer::A1_state;
}


Lexer::~Lexer()
{
	delete [] UTO;
	delete [] UTL;
}

void Lexer::A1_state()
{
	switch (RK)
	{
	case Lexer::letter:
		break;
	case Lexer::digit:
		E2a();
		break;
	case Lexer::arithmetic:
		break;
	case Lexer::relationship:
		break;
	case Lexer::left_par:
		break;
	case Lexer::right_par:
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		A1();
		break;
	case Lexer::newline:
		A1();
		break;
	case Lexer::eof:
		EXIT1();
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::A2_state()
{
	switch (RK)
	{
	case Lexer::letter:
		C2a();
		break;
	case Lexer::digit:
		D1a();
		break;
	case Lexer::arithmetic:
		A2a();
		break;
	case Lexer::relationship:
		H1a();
		break;
	case Lexer::left_par:
		A2h();
		break;
	case Lexer::right_par:
		A3b();
		break;
	case Lexer::dot:
		D6();
		break;
	case Lexer::CR:
		A2();
		break;
	case Lexer::newline:
		A1();
		break;
	case Lexer::eof:
		EXIT1();
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::A3_state()
{
	switch (RK)
	{
	case Lexer::letter:
		B1a();
		break;
	case Lexer::digit:
		D1a();
		break;
	case Lexer::arithmetic:
		A2a();
		break;
	case Lexer::relationship:
		H1a();
		break;
	case Lexer::left_par:
		A2h();
		break;
	case Lexer::right_par:
		A3b();
		break;
	case Lexer::dot:
		D6();
		break;
	case Lexer::CR:
		A3();
		break;
	case Lexer::newline:
		A1();
		break;
	case Lexer::eof:
		EXIT1();
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::B1_state()
{
	switch (RK)
	{
	case Lexer::letter:
		M1();
		break;
	case Lexer::digit:
		break;
	case Lexer::arithmetic:
		break;
	case Lexer::relationship:
		break;
	case Lexer::left_par:
		break;
	case Lexer::right_par:
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		B1();
		break;
	case Lexer::newline:
		break;
	case Lexer::eof:
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::C1_state()
{
	switch (RK)
	{
	case Lexer::letter:
		C2d();
		break;
	case Lexer::digit:
		break;
	case Lexer::arithmetic:
		break;
	case Lexer::relationship:
		break;
	case Lexer::left_par:
		break;
	case Lexer::right_par:
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		C1();
		break;
	case Lexer::newline:
		break;
	case Lexer::eof:
		EXIT3();
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::C2_state()
{
	switch (RK)
	{
	case Lexer::letter:
		B1b();
		break;
	case Lexer::digit:
		A3a();
		break;
	case Lexer::arithmetic:
		A2g();
		break;
	case Lexer::relationship:
		H1b();
		break;
	case Lexer::left_par:
		A2k();
		break;
	case Lexer::right_par:
		A3c();
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		C2();
		break;
	case Lexer::newline:
		A1a();
		break;
	case Lexer::eof:
		EXIT4();
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::D1_state()
{
	switch (RK)
	{
	case Lexer::letter:
		M2();
		break;
	case Lexer::digit:
		D1b();
		break;
	case Lexer::arithmetic:
		A2c();
		break;
	case Lexer::relationship:
		H1c();
		break;
	case Lexer::left_par:
		A2l();
		break;
	case Lexer::right_par:
		A3d();
		break;
	case Lexer::dot:
		D2c();
		break;
	case Lexer::CR:
		D1();
		break;
	case Lexer::newline:
		A1b();
		break;
	case Lexer::eof:
		EXIT3();
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::D2_state()
{
	switch (RK)
	{
	case Lexer::letter:
		M3();
		break;
	case Lexer::digit:
		D2a();
		break;
	case Lexer::arithmetic:
		A2d();
		break;
	case Lexer::relationship:
		H1d();
		break;
	case Lexer::left_par:
		A2m();
		break;
	case Lexer::right_par:
		A3e();
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		D2();
		break;
	case Lexer::newline:
		A1c();
		break;
	case Lexer::eof:
		EXIT4();
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::D3_state()
{
	switch (RK)
	{
	case Lexer::letter:
		break;
	case Lexer::digit:
		D5a();
		break;
	case Lexer::arithmetic:
		D4a();
		break;
	case Lexer::relationship:
		break;
	case Lexer::left_par:
		break;
	case Lexer::right_par:
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		D3();
		break;
	case Lexer::newline:
		break;
	case Lexer::eof:
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::D4_state()
{
	switch (RK)
	{
	case Lexer::letter:
		break;
	case Lexer::digit:
		D5b();
		break;
	case Lexer::arithmetic:
		break;
	case Lexer::relationship:
		break;
	case Lexer::left_par:
		break;
	case Lexer::right_par:
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		D4();
		break;
	case Lexer::newline:
		break;
	case Lexer::eof:
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::D5_state()
{
	switch (RK)
	{
	case Lexer::letter:
		B1c();
		break;
	case Lexer::digit:
		D5c();
		break;
	case Lexer::arithmetic:
		A2e();
		break;
	case Lexer::relationship:
		H1c();
		break;
	case Lexer::left_par:
		A2n();
		break;
	case Lexer::right_par:
		A3f();
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		D5();
		break;
	case Lexer::newline:
		A1d();
		break;
	case Lexer::eof:
		EXIT5();
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::D6_state()
{
	switch (RK)
	{
	case Lexer::letter:
		break;
	case Lexer::digit:
		D2b();
		break;
	case Lexer::arithmetic:
		break;
	case Lexer::relationship:
		break;
	case Lexer::left_par:
		break;
	case Lexer::right_par:
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		D6();
		break;
	case Lexer::newline:
		break;
	case Lexer::eof:
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::E1_state()
{
	switch (RK)
	{
	case Lexer::letter:
		break;
	case Lexer::digit:
		E2b();
		break;
	case Lexer::arithmetic:
		break;
	case Lexer::relationship:
		break;
	case Lexer::left_par:
		break;
	case Lexer::right_par:
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		E1();
		break;
	case Lexer::newline:
		break;
	case Lexer::eof:
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::E2_state()
{
	switch (RK)
	{
	case Lexer::letter:
		B1e();
		break;
	case Lexer::digit:
		E2c();
		break;
	case Lexer::arithmetic:
		A2f();
		break;
	case Lexer::relationship:
		H1f();
		break;
	case Lexer::left_par:
		A2j();
		break;
	case Lexer::right_par:
		A3g();
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		E2();
		break;
	case Lexer::newline:
		A1e();
		break;
	case Lexer::eof:
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::F1_state()
{
	switch (RK)
	{
	case Lexer::letter:
		F2a();
		break;
	case Lexer::digit:
		break;
	case Lexer::arithmetic:
		break;
	case Lexer::relationship:
		break;
	case Lexer::left_par:
		break;
	case Lexer::right_par:
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		F1();
		break;
	case Lexer::newline:
		break;
	case Lexer::eof:
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::F2_state()
{
	switch (RK)
	{
	case Lexer::letter:
		break;
	case Lexer::digit:
		F3a();
		break;
	case Lexer::arithmetic:
		break;
	case Lexer::relationship:
		A2o();
		break;
	case Lexer::left_par:
		break;
	case Lexer::right_par:
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		F2();
		break;
	case Lexer::newline:
		break;
	case Lexer::eof:
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::F3_state()
{
	switch (RK)
	{
	case Lexer::letter:
		break;
	case Lexer::digit:
		break;
	case Lexer::arithmetic:
		break;
	case Lexer::relationship:
		A2o();
		break;
	case Lexer::left_par:
		break;
	case Lexer::right_par:
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		F3();
		break;
	case Lexer::newline:
		break;
	case Lexer::eof:
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::G1_state()
{
	switch (RK)
	{
	case Lexer::letter:
		G1();
		break;
	case Lexer::digit:
		G1();
		break;
	case Lexer::arithmetic:
		G1();
		break;
	case Lexer::relationship:
		G1();
		break;
	case Lexer::left_par:
		G1();
		break;
	case Lexer::right_par:
		G1();
		break;
	case Lexer::dot:
		G1();
		break;
	case Lexer::CR:
		G1();
		break;
	case Lexer::newline:
		A1();
		break;
	case Lexer::eof:
		EXIT1();
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::H1_state()
{
	switch (RK)
	{
	case Lexer::letter:
		C2b();
		break;
	case Lexer::digit:
		D1c();
		break;
	case Lexer::arithmetic:
		A2g();
		break;
	case Lexer::relationship:
		A2p();
		break;
	case Lexer::left_par:
		A2k();
		break;
	case Lexer::right_par:
		A3c();
		break;
	case Lexer::dot:
		D6a();
		break;
	case Lexer::CR:
		H1a();
		break;
	case Lexer::newline:
		A1a();
		break;
	case Lexer::eof:
		EXIT2();
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}
void Lexer::error_state()
{
	switch (RK)
	{
	case Lexer::letter:
		break;
	case Lexer::digit:
		break;
	case Lexer::arithmetic:
		break;
	case Lexer::relationship:
		break;
	case Lexer::left_par:
		break;
	case Lexer::right_par:
		break;
	case Lexer::dot:
		break;
	case Lexer::CR:
		break;
	case Lexer::newline:
		break;
	case Lexer::eof:
		break;
	case Lexer::error:
		break;
	case Lexer::last_transliterator_token_class:
		break;
	default:
		break;
	}
}



void Lexer::A1b( )
{
	DA1D( );
	RSOS = &Lexer::A1_state;
}

void Lexer::A1a( )
{
	addLexem();
	RSOS = &Lexer::A1_state;
}

void Lexer::A1( )
{
	RSOS = &Lexer::A1_state;
}

void Lexer::A1c( )
{
	DA1D( );
	A1a( );
	RSOS = &Lexer::A1_state;
}

void Lexer::A1d( )
{
	DA3D( );
	A1a( );
	RSOS = &Lexer::A1_state;
}

void Lexer::A1e( )
{
	DA1E( );
	A1a( );
	RSOS = &Lexer::A1_state;
}

void Lexer::A2c( )
{
	DA1D( );
	RSOS = &Lexer::A2_state;
}

void Lexer::A2g( )
{
	addLexem();
	RSOS = &Lexer::A2_state;
}

void Lexer::A2a( )
{
	RKL = arithmetic_operation;
	RSOS = &Lexer::A2_state;
}

void Lexer::A2b( )
{
	addLexem();
	RSOS = &Lexer::A2_state;
}

void Lexer::A2( )
{
	RSOS = &Lexer::A2_state;
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
	RSOS = &Lexer::A2_state;
}

void Lexer::A2k( )
{
	addLexem();
	RSOS = &Lexer::A2_state;
}

void Lexer::A2h( )
{
	RKL = left_parenthesis;
	addLexem();
	RSOS = &Lexer::A2_state;
}

void Lexer::A2l( )
{
	DA1D( );
	A2k( );
	RSOS = &Lexer::A2_state;
}

void Lexer::A2m( )
{
	DA2D( );
	A2k( );
	RSOS = &Lexer::A2_state;
}

void Lexer::A2n( )
{
	DA3D( );
	A2k( );
	RSOS = &Lexer::A2_state;
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
	RSOS = &Lexer::A2_state;
}

void Lexer::A2q( )
{
	RKL = lexeme_token_class::END;
	RSOS = &Lexer::A2_state;
}

void Lexer::A2r( )
{
	RKL = lexeme_token_class::IF;
	RSOS = &Lexer::A2_state;
}

void Lexer::A2s( )
{
	RKL = lexeme_token_class::RETURN;
	RSOS = &Lexer::A2_state;
}

void Lexer::A2t( )
{
	RKL = lexeme_token_class::STEP;
	RSOS = &Lexer::A2_state;
}

void Lexer::A2u( )
{
	RKL = lexeme_token_class::TO;
	RSOS = &Lexer::A2_state;
}
void Lexer::A3()
{
	RSOS = &Lexer::A3_state;
}
void Lexer::A3a()
{
	RZN = (RZN + 1) * 26;
	RZN += RU;
	addLexem();
	RSOS = &Lexer::A3_state;
}
void Lexer::A3b()
{
	RKL = right_parenthesis;
	addLexem();
	RSOS = &Lexer::A3_state;
}
void Lexer::A3c()
{
	addLexem();
	RSOS = &Lexer::A3_state;
}
void Lexer::A3d()
{
	DA1D();
	RSOS = &Lexer::A3_state;
}
void Lexer::A3e()
{
	DA2D();
	A3c();
	RSOS = &Lexer::A3_state;
}
void Lexer::A3f()
{
	DA3D();
	A3c();
	RSOS = &Lexer::A3_state;
}
void Lexer::A3g()
{
	DA1E();
	A3c();
	RSOS = &Lexer::A3_state;
}
void Lexer::B1()
{
	RSOS = &Lexer::B1_state;
}
void Lexer::B1a()
{
	ROB = m_init_vector[RZN - 'a'];
	if (ROB == -1) error_method();   //Не уверен в необходимости ветки ELSE
	else
		RSOS = &Lexer::B1_state;
}
void Lexer::B1b()
{
	addLexem();
	RSOS = &Lexer::B1_state;
}
void Lexer::B1c()
{
	DA3D();
	RSOS = &Lexer::B1_state;
}
void Lexer::B1d()
{
	ROB++;
	RSOS = &Lexer::B1_state;
}
void Lexer::B1e()
{
	DA1E();
	B1b();
	RSOS = &Lexer::B1_state;
}
void Lexer::C1()
{
	RSOS = &Lexer::C1_state;
}
void Lexer::C1a()
{
	RKL = end_of_loop;
	RSOS = &Lexer::C1_state;
}
void Lexer::С1b()
{
	//Нет такой функции
}
void Lexer::C2a()
{
	RKL = identifier;
	RSOS = &Lexer::C2_state;
}
void Lexer::C2b()
{
	addLexem();
	RSOS = &Lexer::C2_state;
}
void Lexer::C2d()
{
	RU = RZN;
	RSOS = &Lexer::C2_state;
}
void Lexer::C2()
{
	RSOS = &Lexer::C2_state;
}
void Lexer::D1()
{
	RSOS = &Lexer::D1_state;
}
void Lexer::D1a()
{
	RKL = identifier;
	RCH = RZN;
	RSOS = &Lexer::D1_state;
}
void Lexer::D1b()
{
	RCH *= 10;
	RCH += RZN;
	RSOS = &Lexer::D1_state;
}
void Lexer::D1c()
{
	addLexem();
	RSOS = &Lexer::D1_state;
}
void Lexer::D2()
{
	RSOS = &Lexer::D2_state;
}
void Lexer::D2a()
{
	RS++;
	RCH *= 10;
	RCH += RZN;
	RSOS = &Lexer::D2_state;
}
void Lexer::D2b()
{
	RS = 1;
	RCH = RZN;
	RSOS = &Lexer::D2_state;

}
void Lexer::D2c()
{
	RS = 0;
	RSOS = &Lexer::D2_state;
}
void Lexer::D3()
{
	RSOS = &Lexer::D3_state;
}
void Lexer::D3a()
{
	RS = 0;
	RSOS = &Lexer::D3_state;
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
	RSOS = &Lexer::D4_state;
}

void Lexer::D4( )
{

	RSOS = &Lexer::D4_state;
}

void Lexer::D5a( )
{
	RZN = 1;
	RSOS = &Lexer::D5_state;
}

void Lexer::D5b( )
{
	RP = RZN;
	RSOS = &Lexer::D5_state;
}

void Lexer::D5( )
{
	RSOS = &Lexer::D5_state;
}

void Lexer::D5c( )
{
	RP *= 10;
	RP += RZN;
	RSOS = &Lexer::D5_state;
}
void Lexer::D6()
{
	addLexem();
	RSOS = &Lexer::D6_state;
}
void Lexer::D6a()
{

	RSOS = &Lexer::D6_state;
}
void Lexer::E1()
{
	RSOS = &Lexer::E1_state;
}
void Lexer::E1a()
{
	RKL = lexeme_token_class::transfer;
	RSOS = &Lexer::E1_state;
}
void Lexer::E1b()
{
	RKL = lexeme_token_class::transfer_sub;
	RSOS = &Lexer::E1_state;
}
void Lexer::E2()
{
	RSOS = &Lexer::E2_state;
}
void Lexer::E2a()
{
	RKL = lexeme_token_class::label;
	RSOS = &Lexer::E2_state;
}
void Lexer::E2b()
{
	RSTR = RZN;
	RSOS = &Lexer::E2_state;
}
void Lexer::E2c()
{
	RSTR *= 10;
	RSTR += RZN;
	RSOS = &Lexer::E2_state;
}
void Lexer::F1()
{
	RSOS = &Lexer::F1_state;
}
void Lexer::F1a()
{
	RKL = lexeme_token_class::assignment;
	RSOS = &Lexer::F1_state;
}
void Lexer::F1b()
{
	RKL = lexeme_token_class::FOR;
	RSOS = &Lexer::F1_state;
}
void Lexer::F2()
{
	RSOS = &Lexer::F2_state;
}
void Lexer::F2a()
{
	RU = RZN;
	RSOS = &Lexer::F2_state;
}
void Lexer::F3()
{
	RSOS = &Lexer::F3_state;
}
void Lexer::F3a()
{
	RZN = (RZN + 1) * 26;
	RU += RZN;
	RSOS = &Lexer::F3_state;
}
void Lexer::G1()
{
	RSOS = &Lexer::G1_state;
}
void Lexer::G1a()
{
	RKL = lexeme_token_class::REM;
	RSOS = &Lexer::G1_state;
}
void Lexer::H1()
{
	RSOS = &Lexer::H1_state;
}
void Lexer::H1a()
{
	ROT = RZN;
	RSOS = &Lexer::H1_state;
}
void Lexer::H1b()
{
	addLexem();
	RSOS = &Lexer::H1_state;
}
void Lexer::H1c()
{
	DA1D();
	RSOS = &Lexer::H1_state;
}
void Lexer::H1d()
{
	DA2D();
	H1b();
	RSOS = &Lexer::H1_state;
}
void Lexer::H1e()
{
	DA3D();
	H1b();
	RSOS = &Lexer::H1_state;
}
void Lexer::H1f()
{
	DA1E();
	H1b();
	RSOS = &Lexer::H1_state;
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
	switch (RKL)
	{
	case 3:
		UTL[NTL] = lexeme_token{ lexeme_token_class(RKL), RZN };
		NTL++;
		break;
	case 4:
		UTL[NTL] = lexeme_token{ lexeme_token_class(RKL), ROT };
		NTL++;
		break;
	case 1: case 2: case 5: case 6: case 7: case 8: case 9:
		UTL[NTL] = lexeme_token{ lexeme_token_class(RKL), RU };
		NTL++;
		break;
	default:
		UTL[NTL] = lexeme_token{ lexeme_token_class(RKL), RZN };
		NTL++;
		break;
	}

}
void Lexer::start(std::string filename)
{
	std::ifstream infile(filename);
	std::string line;
	while (std::getline(infile, line))
	{
		for (std::string::iterator it = line.begin(); it != line.end(); it++)
		{
			(this->*RSOS)();
		}
		RK = transliterator_token_class::newline;
		(this->*RSOS)();
	}
	RK = transliterator_token_class::eof;
	(this->*RSOS)();
}
void  Lexer::calculateConstant()
{
	RU = NTO;
	UTO[NTO] = RCH * pow(10, RP);
	NTO++;
}

void Lexer::transliterator(char c)
{
	if (isdigit(c))
	{
		RZN = c - '0';
		RK = transliterator_token_class::digit;
		return;
	}
	if (c <= 'Z' && c >= 'A')
	{
		RZN = c - 'A' + 1;
		RK = transliterator_token_class::letter;
		return;
	}
	switch (c)
	{
	case '+':
		RZN = 1;
		RK = transliterator_token_class::arithmetic;
		break;
	case '-':
		RZN = 2;
		RK = transliterator_token_class::arithmetic;
		break;
	case '*':
		RZN = 3;
		RK = transliterator_token_class::arithmetic;
		break;
	case '/':
		RZN = 4;
		RK = transliterator_token_class::arithmetic;
		break;
	case '%':
		RZN = 5;
		RK = transliterator_token_class::arithmetic;
		break;
	case '=':
		RZN = 1;
		RK = transliterator_token_class::relationship;
		break;
	case '<':
		RZN = 2;
		RK = transliterator_token_class::relationship;
		break;
	case '>':
		RZN = 3;
		RK = transliterator_token_class::relationship;
		break;
	case '(':
		RZN = 0;
		RK = transliterator_token_class::left_par;
		break;
	case ')':
		RZN = 0;
		RK = transliterator_token_class::right_par;
		break;
	case '.':
		RZN = 0;
		RK = transliterator_token_class::dot;
		break;
	case ' ': case 9:
		RZN = 0;
		RK = transliterator_token_class::CR;
		break;

	default:
		RK = transliterator_token_class::error;
		break;
	}
}