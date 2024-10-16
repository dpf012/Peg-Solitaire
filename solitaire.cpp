// UMBC - CMSC 341 - Fall 2024 - Proj0
#include "solitaire.h"

// Preconditions:
// N/A
//
// Postconditions:
// Creates an empty object
Solitaire::Solitaire(){
    m_numRows = 0;
    m_numColumns = 0;
    m_board = nullptr;  
    m_shape = NONE; 
    m_numMarbles = 0; 
} 

// Preconditions:
// Board must be ENGLISH/DIAMOND/invalid. Memory must be allocated.
//
// Postconditions:
// Memory is allocated. Boards are filled with appropriate shape data.
// Invalid shapes are set to default state.
Solitaire::Solitaire(BOARDSHAPE board){

    // set board to inputted shape
    m_shape = board;

    // sets dimensions based on shape
    if (board == ENGLISH){
        m_numRows = m_numColumns = ENGLISHSIZE;
    } else if (board == DIAMOND){
        m_numRows = m_numColumns = DIAMONDSIZE;
    } else { 
        m_numRows = m_numColumns = m_numMarbles = 0;   // invalid shapes
        m_board = nullptr;
        return;
    }

    // allocates memory for the 2-D array [m_board]
    m_board = new int*[m_numRows];
    for (int i = 0; i < m_numRows; ++i){
        m_board[i] = new int[m_numColumns];
    }

    // intializes ENGLISH board
    if (board == ENGLISH){
        m_numMarbles = NUMENGLISHMARBLES;
        for (int i = 0; i < m_numRows; ++i){
            for (int j = 0; j < m_numColumns; ++j){
                // appropriate rows and columns in the corners are out
                if ((i < 2 || i > 4) && (j < 2 || j > 4)){
                    m_board[i][j] = OUT;
                // board center is the hole 
                } else if (i == 3 && j == 3){
                    m_board[i][j] = HOLE;
                // everything else is filled with marbles 
                } else{
                    m_board[i][j] = MARBLE; 
                }
            }
        }
    // initializes DIAMOND board
    } else if (board == DIAMOND){
        m_numMarbles = NUMDIAMONDMARBLES;
        for (int i = 0; i < m_numRows; ++i){
            for (int j = 0; j < m_numColumns; ++j){
                // appropriate rows and columns in the corners are out
                if ((i + j < 4) || (i + j > 12) || (j - i > 4) || (i - j > 4)){
                    m_board[i][j] = OUT; 
                // board center is the hole 
                } else if (i == 4 && j == 4){
                    m_board[i][j] = HOLE; 
                // everything else is filled with marbles
                } else{
                    m_board[i][j] = MARBLE; 
                }
            }
        }
    }    
}

// Preconditions:
// rhs must be a valid Solitaire object.
//
// Postconditions:
// New Solitaire object is created with same dimensions as rhs.
// Deep copy is done.
Solitaire::Solitaire(const Solitaire & rhs){
    
    // copy member data variables
    m_numRows = rhs.m_numRows;
    m_numColumns = rhs.m_numColumns;
    m_shape = rhs.m_shape;
    m_numMarbles = rhs.m_numMarbles;

    if (rhs.m_board != nullptr){
        m_board = new int*[m_numRows];  // allocate new memory for board
        for (int i = 0; i < m_numRows; ++i){
            m_board[i] = new int[m_numColumns];
        }
        for (int i = 0; i < m_numRows; ++i){
            for (int j = 0; j < m_numColumns; ++j){
                m_board[i][j] = rhs.m_board[i][j];  // copies board contents
            }
        }
    } else{
        m_board = nullptr;  // no memory allocated if board is empty
    }
}

// Preconditions:
// N/A
//
// Postconditions:
// All board memory is freed.
Solitaire::~Solitaire(){
    clear();   
}

// Preconditions:
// N/A
//
// Postconditions:
// All board memory is freed.
void Solitaire::clear(){

    // checks if board is empty and deallocates memory for m_board
    if (m_board != nullptr){
        for (int i = 0; i < m_numRows; ++i){
            delete[] m_board[i];
        }

        delete[] m_board;
    }

    // reset all member variables to default
    m_numRows = 0;
    m_numColumns = 0;
    m_board = nullptr;
    m_shape = NONE;
    m_numMarbles = 0;
}

// Preconditions:
// origin, destination are valid as a marble & hole respectively.
// There must be a marble to jump over as part of the move.
//
// Postconditions:
// origin -> destination. Marble in between origin and destination is
// removed. Returns true/false depending on validity of move. 
bool Solitaire::play(pair<int,int> origin, pair<int,int> destination){
    
    // sets origin pair values appropriately
    int orgRow = origin.first;
    int orgCol = origin.second;

    // sets destination pair values appropriately
    int destRow = destination.first;
    int destCol = destination.second;

    // checks if orgRow coordinates are out of bounds
    if (orgRow < 0 || orgRow >= m_numRows 
        || orgCol < 0 || orgCol >= m_numColumns){
            return false;
        } 
    // checks if destRow coordinates are out of bounds
    if (destRow < 0 || destRow >= m_numRows 
        || destCol < 0 || destCol >= m_numColumns){
        return false; 
    }

    // Move Validity:
    // - move must start at marble 
    // - destination must be a hole 
    if (m_board[orgRow][orgCol] != MARBLE || m_board[destRow][destCol] != HOLE) {
        return false; 
    }
    
    // move can only proceed 2 spaces vertically/horizontally
    // and must pass over a marble
    if (orgCol == destCol && abs(orgCol - destCol) == 2
        && m_board[( (orgRow + destRow) / 2)][orgCol] == MARBLE){ // vertical move

        // remove and reset appropriate spaces
        m_board[orgRow][orgCol] = HOLE;
        m_board[( (orgRow + destRow) / 2)][orgCol] = HOLE;
        m_board[destRow][orgCol] = MARBLE;    
    
    } else if (orgRow == destRow && abs(orgRow - destRow) == 2
               && m_board[orgRow][( (orgCol + destCol) / 2)] == MARBLE){ // horizontal move
        
        // remove and reset appropriate spaces
         m_board[orgRow][orgCol] = HOLE;
         m_board[orgRow][( (orgRow + destRow) / 2)] = HOLE;
         m_board[destRow][destCol] = MARBLE;
    } else { 
        return false; // any other move is invalid
    }
    return true;
}

// Postconditions:
// board must be valid. Memory must be allocated.
//
// Postconditions:
// new Solitaire object is created if board is different.
// Re-initializes object if same. 
void Solitaire::changeBoard(BOARDSHAPE board){
    
    // check for same shape
    if (board == m_shape) {
        clear(); // reset board
        m_shape = board;
    }

    if (board == ENGLISH) {
        // initializes ENGLISH board
        m_numRows = m_numColumns = ENGLISHSIZE;
        m_numMarbles = NUMENGLISHMARBLES;
        m_board = new int*[m_numRows];
        for (int i = 0; i < m_numRows; ++i) {
                m_board[i] = new int[m_numColumns];
        }
        for (int i = 0; i < m_numRows; ++i) {
            for (int j = 0; j < m_numColumns; ++j) {
                if ((i < 2 || i > 4) && (j < 2 || j > 4)) {
                    m_board[i][j] = OUT; // appropriate rows and columns in the corners are out
                } else if (i == 3 && j == 3) {
                    m_board[i][j] = HOLE; // // board center is the hole
                } else {
                    m_board[i][j] = MARBLE; // everything else is filled with marbles
                }
            }
        }
    } else if (board == DIAMOND) {
        // initializes DIAMOND board
        m_numRows = m_numColumns = DIAMONDSIZE;
        m_numMarbles = NUMDIAMONDMARBLES;
        m_board = new int*[m_numRows];
        for (int i = 0; i < m_numRows; ++i) {
                m_board[i] = new int[m_numColumns];
        }
        for (int i = 0; i < m_numRows; ++i) {
            for (int j = 0; j < m_numColumns; ++j) {
                if ((i + j < 4) || (i + j > 12) || (j - i > 4) || (i - j > 4)) {
                    m_board[i][j] = OUT; // appropriate rows and columns in the corners are out
                } else if (i == 4 && j == 4) {
                    m_board[i][j] = HOLE; // board center is the hole
                } else {
                    m_board[i][j] = MARBLE; // everything else is filled with marbles
                }
            }
        }
    }   else{

        // different shape, create a new board with the new shape
        Solitaire newBoard(board);
    }
}

// Postconditions:
// board must be valid. Memory must be allocated.
//
// Postconditions:
// new Solitaire object is created if board is different.
// Returns true if successfully reinitialized.
bool Solitaire::newBoard(){
    if (m_shape == NONE || m_shape == FRENCH 
        || m_shape != ENGLISH || m_shape != DIAMOND){
        return false; // shape not supported
    } 

    clear();

    // re-intialize ENGLISH board
    if (m_shape == ENGLISH) {
        m_numRows = m_numColumns = ENGLISHSIZE;
        m_numMarbles = NUMENGLISHMARBLES;
        m_board = new int*[m_numRows];
        for (int i = 0; i < m_numRows; ++i) {
            m_board[i] = new int[m_numColumns];
        }
        for (int i = 0; i < m_numRows; ++i) {
            for (int j = 0; j < m_numColumns; ++j) {
                if ((i < 2 || i > 4) && (j < 2 || j > 4)) {
                    m_board[i][j] = OUT; // appropriate rows and columns in the corners are out
                } else if (i == 3 && j == 3) {
                    m_board[i][j] = HOLE; // board center is the hole
                } else {
                    m_board[i][j] = MARBLE; // everything else is filled with marbles
                }
            }
        }
    // re-initialize DIAMOND board
    } else if (m_shape == DIAMOND) {
        m_numRows = m_numColumns = DIAMONDSIZE;
        m_numMarbles = NUMDIAMONDMARBLES;
        m_board = new int*[m_numRows];
        for (int i = 0; i < m_numRows; ++i) {
            m_board[i] = new int[m_numColumns];
        }
        for (int i = 0; i < m_numRows; ++i) {
            for (int j = 0; j < m_numColumns; ++j) {
                if ((i + j < 4) || (i + j > 12) || (j - i > 4) || (i - j > 4)) {
                    m_board[i][j] = OUT; // appropriate rows and columns in the corners are out
                } else if (i == 4 && j == 4) {
                    m_board[i][j] = HOLE; // board center is the hole
                } else {
                    m_board[i][j] = MARBLE; // everything else is filled with marbles
                }
            }
        }
    }

    return true;
}

// ** debugging purposes **
void Solitaire::dumpBoard(){
    // this is to facilitate debugging 
    cout << "  ";
    for (int k=0;k<m_numColumns;k++){
        cout << k << " ";
    }
    cout << endl;
    for (int i=1;i <= m_numRows;i++){
        cout << i-1 << " ";
        for (int j=1;j<=m_numColumns;j++){
            if (m_board[i-1][j-1] == OUT)
                cout << "  ";
            else if (m_board[i-1][j-1] == HOLE)
                cout << BLACKSTAR;
            else
                cout << REDSTAR;
        }
        cout << endl;
    }
    cout << endl;
}
int Solitaire::reportNumMarbles(){
    // this is to facilitate debugging 
    cout << "You have " << m_numMarbles << " marbles to remove!" << endl;
    return m_numMarbles;
}

// may be needed
int Solitaire::getNumRows(){
    return m_numRows;
}
int Solitaire::getNumColumns(){
    return m_numColumns;
}
int ** Solitaire::getBoard(){
    return m_board;
}
int Solitaire::getNumMarbles(){
    return m_numMarbles;
}