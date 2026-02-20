#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>
#include "lexer.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>


enum stmt_type { INPUT_STMT, OUTPUT_STMT, ASSIGN_STMT };


struct stmt {
    stmt_type type;			
    std::string var;
    stmt* next;
};

struct poly_header_t
{
    std::string name;
    std::vector<std::string> parameterName;
    int line_no;
};



class Parser 
{
public:
  Parser();
  void parse_input();

  void parse_program();
  void parse_tasks_section();
  void parse_num_list();

  void parse_poly_section();
  void parse_poly_decl_list();
  void parse_poly_decl();
  void parse_poly_header();
  std::vector<std::string> id_list();
  Token parse_poly_name();
  void parse_poly_body();

  void parse_term_list();
  void parse_term();

  void parse_monomial_list();
  void parse_monomial();
  void parse_primary();
  void parse_exponent();
  void parse_add_operator();
  void parse_coefficient();

  void parse_execute_section();
  void execute_input_statements();
  void execute_program();
  void parse_statement_list();
  void parse_statement();
  void parse_input_statement();
  void parse_output_statement();
  void parse_assign_statement();

  void parse_poly_evaluation();
  int parse_argument_list();
  void parse_argument();
  void parse_inputs_section();
  void parse_inputs_num_list();
  


bool tasks[7];
int nextAvailable;

stmt* stmtList;
std::vector<int> mem;
std::vector<int> inputValues;

std::vector<std::string> curr_POLY;
std::vector<int> undefined_polynomial;
std::vector<int> wrong_argument_count;
std::vector<int> line_duplicate;
std::vector<int> invalid_monomial;
std::unordered_set<std::string> declaredPOLY;
std::unordered_map<std::string, int> symbolTable;
std::vector<poly_header_t> poly_header;


private:
  LexicalAnalyzer lexer;
  void syntax_error();
  Token expect(TokenType expected_type);

};

#endif
