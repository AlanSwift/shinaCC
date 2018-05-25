struct A_statement_
{
	enum{
		A_labeledStm,A_compdStm,A_expStm,A_selectStm,
		A_iterStm,A_jmpStm
	}kind;
	union{
		struct {
			enum{
				B_identifier,
				B_case,
				B_default
			}kind;
			union{
				struct 
				{
					S_symbol identifier;
					A_statement stm;
				}idenStm;
				struct
				{
					A_exp exp;
					A_statement stm;
				}caseStm;
				struct
				{
					A_statement stm;
				}defultStm;
			}u;
			
		}labeled;
		struct{
			A_declarationLst decLst;
			A_statementList stmLst;
		}compdStm;
		struct
		{
			A_exp exp;
		}expStm;
		struct
		{
			enum{
				B_if,B_switch
			}kind;
			A_exp exp;
			A_statement stm;
		}selectStm;
		struct
		{
			enum{
				B_for,B_while,B_doWhile
			}kind;
			A_exp exp;
			A_statement stm;
			A_statement expstm1,expstm2;
			A_exp exp1;
		}iterStm;
		struct
		{
			S_symbol actionKind;
			S_symbol identifier;
			A_exp exp;

		}jmpStm;
		
	}u;

	
};
struct A_statementlist_{
    struct A_statement stm;
    struct A_statementlist next;
};
A_statementList A_StmList(A_pos,A_statementlist lst,A_statement stm);

A_statement A_IdentifierLabeledStatement(A_pos pos, S_symbol identifier, A_statement stm);
A_statement A_CaseLabeledStatement(A_pos pos, A_exp exp, A_statement stm);
A_statement A_DefaultLabeledStatement(A_pos pos, A_statement stm);
A_statement A_CompdStatement(A_pos pos, A_statementlist stmList,A_declarationlist decList);
A_statement A_ExpStatement(A_pos pos,A_exp exp);
A_statement A_IfSelectStatement(A_pos pos, A_exp exp, A_statement stm,A_statement elseStm);
A_statement A_SwitchSelectStatement(A_pos pos, A_exp exp, A_statement stm);
A_statement A_ForSelectStatement(A_pos pos,A_statement stm1, A_statement stm2, A_exp exp,A_statement body);
A_statement A_WhileSelectStatement(A_pos,A_exp exp, A_statement stm);
A_statement A_DoWhileSelectStatement(A_pos, A_statement stm, A_exp exp);
A_statement A_JumpStatement(A_pos,S_symbol actionKind,S_symbol identifier, A_exp exp);