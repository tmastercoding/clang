#include <iostream>
#include <string>
using namespace std;

class Calc {
    private:
        int pre;
        int post;
        char op;
        int result;

    public:
        Calc(string num1, string num2, string expression ) {
            this->setPre( num1 );
            this->setPost( num2 );
            this->setOp( expression );
            this->setResult();

        }

        void setPre( string num ) {
            this->pre = stoi( num );        
        }

        void setPost( string num ) {
            this->post = stoi( num );
        }
        
        void setOp( string text ) {
            this->op = text[0]; 
        }

        int getPre( ) {
            return this->pre;
        }

        int getPost( ) {
            return this->post;
        }

        int getOp() {
            return this->op;
        }

        void setResult( ) {

            switch ( this->getOp() )
            {
            case '+':
                this->result = this->getPre() + this->getPost();
                break;

            case '-':
                this->result = this->getPre() - this->getPost();
                break;
            
            default:
                break;
            }

        }

        int getResult() {
            return this->result;
        }
};

int main() {
    string expression;
    string pre;
    string post;

    cin >> pre >> expression >> post;

    // cout << "user input is :" << endl;

    // cout << pre << endl;
    // cout << expression << endl;
    // cout << post << endl;

    Calc calc( pre, post, expression );

    cout << "Result is : " << calc.getResult() << endl;

    return 0;
}