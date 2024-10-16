// UMBC - CMSC 341 - Fall 2024 - Proj0
#include "solitaire.h"

class Tester{
    public:
    // 1a,b,c,d. COMPLETE ( constructor - done in int main() )
    bool testCopyConstructorError(const Solitaire& solitaire); // 2a. COMPLETE 
    bool testCopyConstructorNormal(const Solitaire& solitaire);// 2b. COMPLETE
    bool testDestructorError();  // 3a. COMPLETE
    bool testDestructorNormal(); // 3b. COMPLETE
    bool testClearError();      // 4a. COMPLETE
    bool testClearNormal();     // 4b. COMPLETE
    bool testNewBoardError();   // 5a. COMPLETE   
    bool testNewBoardNormal();  // 5b. COMPLETE 
    bool testChangeBoard();     // 6. COMPLETE     
};

int main(){

    // DEFAULT CONSTRUCTOR NOT CHECKED
    cout << "*************************************" << endl;
    cout << "******Test Default Constructor*******" << endl;
    cout << endl;
    cout << "           [NOT CHECKED]             " << endl;
    cout << endl;
    
    // TEST CONSTRUCTOR FOR VALID/INVALID SHAPES
    cout << "************************************" << endl;
    cout << "**********Test Constructor**********" << endl;
    cout << endl;
    cout << "Create an ENGLISH board:" << endl;
    Solitaire pegSolitaireEnglish(ENGLISH);        // valid
    cout << "[Marble Count] " << endl;           // print marble count
    cout << "Normal: 32" << endl;
    cout << pegSolitaireEnglish.reportNumMarbles() << " <- Actual" << endl;
    if (pegSolitaireEnglish.reportNumMarbles() == 32){
        cout << "[PASSED]"<< endl;
    }
    cout << endl; 
 
    cout << "Create a DIAMOND board:" << endl;
    Solitaire pegSolitaireDiamond(DIAMOND);        // valid
    cout << "[Marble Count] " << endl;           // print marble count
    cout << "Normal: 40" << endl;
    cout << pegSolitaireDiamond.reportNumMarbles() << " <- Actual" << endl;
    if (pegSolitaireDiamond.reportNumMarbles() == 40){
        cout << "[PASSED]"<< endl;
    }
    cout << endl;
 
    cout << "Create a FRENCH board:" << endl;
    Solitaire pegSolitaireFrench(FRENCH);         // invalid
    cout << "[Marble Count] " << endl;
    cout << "Normal: 0 " << endl;
    cout << pegSolitaireFrench.reportNumMarbles() << " <- Actual" << endl;
    if (pegSolitaireFrench.reportNumMarbles() == 0){
        cout << "[PASSED]"<< endl;
    }
    cout << endl;
 
    cout << "Create a NONE board:" << endl;
    Solitaire pegSolitaireNone(NONE);           // invalid
    cout << "[Marble Count] " << endl;
    cout << "Normal: 0 " << endl;
    cout << pegSolitaireNone.reportNumMarbles() << " <- Actual" << endl;
    if (pegSolitaireNone.reportNumMarbles() == 0){
        cout << "[PASSED]"<< endl;
    }
    cout << endl;
 
    cout << "************************************" << endl;

    // TEST COPY CONSTRUCTOR FOR CORRECT DUPLICATION 
    cout << "********Test Copy Constructor*******" << endl;
    Solitaire copyConstructorNormal(DIAMOND);
    Tester trialNormal;
    cout << endl;
    if (trialNormal.testCopyConstructorNormal(copyConstructorNormal)){
        cout << "[NORMAL]" << endl;
        cout << "\nCopy constructor test normal case passed!" << endl;
    } else {
        cout << "[NORMAL]" << endl;
        cout << "\nCopy constructor test normal case failed!" << endl;
    }
    cout << endl;
    Solitaire copyConstructorError(FRENCH);
    Tester trialError;
    if (trialError.testCopyConstructorError(copyConstructorError)){
        cout << "[ERROR]" << endl;
        cout << "\nCopy constructor test error case passed!" << endl;
    } else {
        cout << "[ERROR]" << endl;
        cout <<"\nCopy constructor test error case failed!" << endl;
    }
    cout << endl;
    cout << "*************************************" << endl;

    // TEST DESTRUCTOR FOR PROPER MEMORY DEALLOCATION
    cout << "**********Test Destructor***********" << endl;
    cout << endl;
    cout << "[NORMAL]" << endl;
    Tester trialDestructorNormal;
    if (trialDestructorNormal.testDestructorNormal()){
        cout << "Destructor called." << endl;
        cout << "     [PASSED]     " << endl;
        cout << endl;
    } else {
        cout << "Destructor not called." << endl;
        cout << "     [FAILED]     " << endl;
        cout << endl;
    }
    cout << "[ERROR]" << endl;
    Tester trialDestructorError;
    if (trialDestructorError.testDestructorError()){
        cout << "Destructor called." << endl;
        cout << "     [PASSED]     " << endl;
        cout << endl;
    } else {
        cout << "Destructor not called." << endl;
        cout << "     [FAILED]     " << endl;
        cout << endl;
    }

    cout << "************************************" << endl;

    // TEST CLEAR FOR PROPER RE-INITIALIZATION
    cout << "************Test Clear**************" << endl;
    cout << endl;
    cout << "[NORMAL]" << endl;
    Tester trialClearNormal;
    if (trialClearNormal.testClearNormal()){
        cout << "[PASSED]" << endl;
        cout << endl;
    } else {
        cout << "[FAILED]" << endl;
        cout << endl;
    }
    cout << "[ERROR]" << endl;
    Tester trialClearError;
    if (trialClearError.testClearError()){
        cout << "[PASSED]" << endl;
        cout << endl;
    } else {
        cout << "[FAILED]" << endl;
        cout << endl;
    }

    cout << "************************************" << endl;
    // TEST NEW BOARD FOR PROPER MEMORY DEALLOCATION
    cout << "************Test newBoard***********" << endl;
    cout << endl;
    cout << "[ERROR]" << endl;
    Tester trialNewBoardError;
    if (trialNewBoardError.testNewBoardError()){
        cout << endl;
        cout << "[PASSED]" << endl;
        cout << endl;
    } else {
        cout << endl;
        cout << "[FAILED]" << endl;
        cout << endl;
    }
    cout << "[NORMAL]" << endl;
    Tester trialNewBoardNormal;
    if (trialNewBoardNormal.testNewBoardNormal()){
        cout << endl;
        cout << "[PASSED]" << endl;
        cout << endl;
    } else {
        cout << endl;
        cout << "[FAILED]" << endl;
        cout << endl;
    }
    cout << "************************************" << endl;
    cout << "*********Test Change Board**********" << endl;
    Tester trialChangeBoard;
    cout << endl;
    if (trialChangeBoard.testChangeBoard()){
        cout << endl;
        cout << "[PASSED]" << endl;
        cout << endl;
    } else {
        cout << endl;
        cout << "[FAILED]" << endl;
        cout << endl;
    }
    // PLAY UNFINISHED
    cout << "************************************" << endl;
    cout << "*************Test Play**************" << endl;
    cout << endl;
    cout << "            [UNFINISHED]            " << endl;
    cout << endl;
    
    // DUMP BOARD NOT CHEKED
    cout << "************************************" << endl;
    cout << "*************DUMP BOARD*************" << endl;
    cout << endl;
    cout << "            [NOT CHECKED]           " << endl;
    cout << endl;

    // REPORT NUM MARBLES NOT CHECKED
    cout << "************************************" << endl;
    cout << "*********REPORT NUM MARBLES*********" << endl;
    cout << endl;
    cout << "            [NOT CHECKED]           " << endl;
    cout << endl;
    cout << "************************************" << endl;
    cout << "************************************" << endl;

    return 0;

}

// tests copy constructor with an invalid board shape
bool Tester::testCopyConstructorError(const Solitaire& solitaire){
    Solitaire copy1(solitaire);
     if (solitaire.m_numColumns == copy1.m_numColumns && 
        solitaire.m_numRows == copy1.m_numRows &&
        solitaire.m_shape == copy1.m_shape &&
        solitaire.m_numMarbles == copy1.m_numMarbles && 
        solitaire.m_board != copy1.m_board){
        for (int i=0;i<solitaire.m_numRows;i++){
            for (int j=0;j<solitaire.m_numColumns;j++)
            {
                if ((solitaire.m_board[i][j] != copy1.m_board[i][j]) ||   //check the value
                    (solitaire.m_board[i] == copy1.m_board[i])){          //check the ith pointer
                    return false;
                }
            }
        }
        return true;// everything is correct
    }
    else return false;//everything else
}

// tests copy constructor with valid board shape
bool Tester::testCopyConstructorNormal(const Solitaire& solitaire){
    Solitaire copy(solitaire);
    if (solitaire.m_numColumns == copy.m_numColumns && 
        solitaire.m_numRows == copy.m_numRows &&
        solitaire.m_shape == copy.m_shape &&
        solitaire.m_numMarbles == copy.m_numMarbles && 
        solitaire.m_board != copy.m_board){
        for (int i=0;i<solitaire.m_numRows;i++){
            for (int j=0;j<solitaire.m_numColumns;j++)
            {
                if ((solitaire.m_board[i][j] != copy.m_board[i][j]) ||   //check the value
                    (solitaire.m_board[i] == copy.m_board[i])){          //check the ith pointer
                    return false;
                }
            }
        }
        return true;// everything is correct
    }
    else return false;//everything else
}

// tests destructor with an invalid board shape 
bool Tester::testDestructorError(){
    try{
        Solitaire* destructorTestFrench = new Solitaire(FRENCH);
        delete destructorTestFrench;
        return true;
    } catch (const exception& e) {
        cerr << e.what(); 
        return false;
    }
}

// tests destructor with valid board shape 
bool Tester::testDestructorNormal(){
    try{
        Solitaire* destructorTestEnglish = new Solitaire(ENGLISH);
        delete destructorTestEnglish;
        return true;
    } catch (const exception& e) {
        cerr << e.what(); 
        return false;
    }
}

// tests clear with an invalid board shape
bool Tester::testClearError(){
    Solitaire solitaireError(FRENCH);
    solitaireError.clear();
    if (solitaireError.m_numRows == 0 
        && solitaireError.m_numColumns == 0 
        && solitaireError.m_board == nullptr
        && solitaireError.m_shape == NONE 
        && solitaireError.m_numMarbles == 0){
            cout << "All member variables should be set to 0." << endl;
            cout << "m_numRows: " << solitaireError.m_numRows << endl;
            cout << "m_numColumns: " << solitaireError.m_numColumns << endl;
            cout << "m_board: " << solitaireError.m_board << endl;
            cout << "m_shape: " << solitaireError.m_shape << endl;
            cout << "m_numMarbles: " << solitaireError.m_numMarbles << endl;
            return true;
    } else {
        return false;
    }
}

// tests clear with valid board shape
bool Tester::testClearNormal(){
    Solitaire solitaireNormal(ENGLISH);
    solitaireNormal.clear();
    if (solitaireNormal.m_numRows == 0 
        && solitaireNormal.m_numColumns == 0 
        && solitaireNormal.m_board == nullptr
        && solitaireNormal.m_shape == NONE 
        && solitaireNormal.m_numMarbles == 0){
            cout << "All member variables should be set to default." << endl;
            cout << "m_numRows: " << solitaireNormal.m_numRows << endl;
            cout << "m_numColumns:" << solitaireNormal.m_numColumns << endl;
            cout << "m_board: " << solitaireNormal.m_board << endl;
            cout << "m_shape" << solitaireNormal.m_shape << endl;
            cout << "m_numMarbles" << solitaireNormal.m_numMarbles << endl;
            return true;
    } else {
        return false;
    }
}

// tests newBoard with an invalid shape
bool Tester::testNewBoardError(){
    Solitaire solitaireNewBoardError;
    if (solitaireNewBoardError.newBoard() == true){
        cout << "Empty board test failed." << endl;
        return false;
    } else {
        cout << "Empty board test passed." << endl;
        return true;
    }
}

// tests newBoard with valid board shape
bool Tester::testNewBoardNormal(){
    Solitaire solitaireNewBoardNormal(ENGLISH);
    if (solitaireNewBoardNormal.newBoard() != false){
        cout << "Valid board test failed." << endl;
        cout << endl;
        cout << "          Expected:        Actual:" << endl;
        cout << "Rows:        7               " << solitaireNewBoardNormal.m_numRows 
             << endl;
        cout << "Columns:     7               " << solitaireNewBoardNormal.m_numColumns
             << endl;
        cout << "Marbles:    32              " << solitaireNewBoardNormal.m_numMarbles
             << endl;
        return false;
    } else {
        cout << "Valid board test passed." << endl;
        cout << "          Expected:        Actual:" << endl;
        cout << "Rows:        7               " << solitaireNewBoardNormal.m_numRows 
             << endl;
        cout << "Columns:     7               " << solitaireNewBoardNormal.m_numColumns
             << endl;
        cout << "Marbles:    32              " << solitaireNewBoardNormal.m_numMarbles
             << endl;
        return true;
    }
}

// tests changeBoard with same board shape to check for re-initialization
// tests changeBoard with different shape to check for new object creation
bool Tester::testChangeBoard() {

    Solitaire solitaireTest(ENGLISH);
    
    int initialRows = solitaireTest.m_numRows;
    int initialColumns = solitaireTest.m_numColumns;
    int initialMarbles = solitaireTest.m_numMarbles;

    // same shape
    solitaireTest.changeBoard(ENGLISH);
    
    if (solitaireTest.m_numRows != initialRows ||
        solitaireTest.m_numColumns != initialColumns ||
        solitaireTest.m_numMarbles != initialMarbles) {
        cout << "          Expected:        Actual:" << endl;
        cout << "Rows:        7               " << solitaireTest.m_numRows 
             << endl;
        cout << "Columns:     7               " << solitaireTest.m_numColumns
             << endl;
        cout << "Marbles:    32              " << solitaireTest.m_numMarbles
             << endl;
        return false;     
    }

    // change to different shape 
    solitaireTest.changeBoard(DIAMOND);
    
    if (solitaireTest.m_numRows != DIAMONDSIZE ||
        solitaireTest.m_numColumns != DIAMONDSIZE ||
        solitaireTest.m_numMarbles != NUMDIAMONDMARBLES) {
        cout << "          Expected:        Actual:" << endl;
        cout << "Rows:        9               " << solitaireTest.m_numRows 
             << endl;
        cout << "Columns:     9               " << solitaireTest.m_numColumns
             << endl;
        cout << "Marbles:    9              " << solitaireTest.m_numMarbles
             << endl;
        return false;  
    }

    cout << "          Expected:        Actual:" << endl;
    cout << "Rows:        7               " << solitaireTest.m_numRows 
         << endl;
    cout << "Columns:     7               " << solitaireTest.m_numColumns
         << endl;
    cout << "Marbles:    32              " << solitaireTest.m_numMarbles
         << endl;
    return true;  
}
