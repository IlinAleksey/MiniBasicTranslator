#pragma once
#include "Hashtable.h"
#include <iostream>
#include <vector>
class Lexer
{
	
	enum lexeme_token_class
	{
		label=1, identifier, arithmetic_operation, relationship_operation, end_of_loop, assignment,FOR, transfer, transfer_sub, 
		left_parenthesis, right_parenthesis, IF, RETURN, END, TO, STEP, REM, ERROR_LEXEME, END_OF_FILE, LAST_LEXEME_TOKEN_CLASS
	};
	struct lexeme_token
	{
		lexeme_token_class m_class;
		int m_value;
	};
	enum transliterator_token_class
	{
		letter, digit, arithmetic, relationship, left_par, right_par, dot, CR, newline, eof, last_transliterator_token_class
	};
	struct transliterator_token
	{
		transliterator_token_class m_class;
		int m_value;
	};
	struct id
	{
		int m_name;
		float m_value;
	};
	enum state
	{
		A1_state, A2_state, A3_state, B1_state, C1_state, C2_state, D1_state,
		D2_state, D3_state, D4_state, D5_state, D6_state, E1_state, E2_state,
		F1_state, F2_state, F3_state, G1_state, H1_state, ERROR_state, LAST_STATE
	};
	typedef void(Lexer::*lexer_method)();
	struct transition_table_element
	{
		char symbol;
		int alternative;
		lexer_method method;
	};
	std::vector<int> m_init_vector;
	std::vector<transition_table_element> m_transition_table;

	enum relation
	{ 
		equal, less, more, notequal, lessorequal, moreorequal 
	};
	transliterator_token transliterator(char symbol);
	
	Hashtable UTS;
	id* UTO;
	lexeme_token* UTL;
	int NTO; //Указатель на первый свободный элемент в ТО
	int NTL; //Указатель на первый свободный элемент в ТL
	int RCH; //регистр числа
	int RZ; //регистр знака порядка
	int RP; //регистр порядка
	int RS; //регистр счетчика
	int RKL; //регистр класса лексем
	int ROT; //регистр значения отношения
	int RZN; //регистр значения символа
	int RSOS; //регистр состояния
	int ROB; //регистр обнаружения
	int RK; //регистр значения класса символа
	int RSTR; //регистр строки
	int RU; //Регистр указателя

	lexer_method CUR_STATE;

	
	void A1( );
	void A1a( );
	void A1b( );
	void A1c( );
	void A1d( );
	void A1e( );
	void A2( );
	void A2a( );
	void A2b( );
	void A2c( );
	void A2d( );
	void A2e( );
	void A2f( );
	void A2g( );
	void A2h( );
	void A2i( );
	void A2j( );
	void A2k( );
	void A2l( );
	void A2m( );
	void A2n( );
	void A2o( );
	void A2p( );
	void A2q( );
	void A2r( );
	void A2s( );
	void A2t( );
	void A2u( );
	void A3( );
	void A3a( );
	void A3b( );
	void A3c( );
	void A3d( );
	void A3e( );
	void A3f( );
	void A3g( );
	void B1( );
	void B1a( );
	void B1b( );
	void B1c( );
	void B1d( );
	void B1e( );
	void C1( );
	void C1a( );
	void С1b( );
	void C2a( );
	void C2b( );
	void C2d( );
	void C2( );
	void D1( );
	void D1a( );
	void D1b( );
	void D1c( );
	void D2( );
	void D2a( );
	void D2b( );
	void D2c( );
	void D3( );
	void D3a( );
	void D4( );
	void D4a( );
	void D5( );
	void D5a( );
	void D5b( );
	void D5c( );
	void D6( );
	void D6a( );
	void E1( );
	void E1a( );
	void E1b( );
	void E2( );
	void E2a( );
	void E2b( );
	void E2c( );
	void F1( );
	void F1a( );
	void F1b( );
	void F2( );
	void F2a( );
	void F3( );
	void F3a( );
	void G1( );
	void G1a( );
	void H1( );
	void H1a( );
	void H1b( );
	void H1c( );
	void H1d( );
	void H1e( );
	void H1f( );
	void M1( );
	void M2( );
	void M3( );
	void EXIT1( );
	void EXIT2( );
	void EXIT3( );
	void EXIT4( );
	void EXIT5( );
	void EXIT6( );
	void DA1D( );
	void DA1E( );
	void DA2D( );
	void DA3D( );
	void DA1LOOP( );
	void error_method();
	void addLexem();
	void calculateConstant();
public:
	void start(std::string filename);
	Lexer();
	~Lexer();
};

