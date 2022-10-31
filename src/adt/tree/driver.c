#include "stdio.h"
#include "wordmachine.h"
#include "tree.h"

int main(){
    Word dir = {"../../config/resep/configresep.txt", 27};

    STARTWORDFILE(dir.TabWord);
    ListWord LFile;
    createListWord(&LFile);
    LFile = readLineFile();
    

    ListTree listResep;
    CreateListTree(&listResep);
    listResep.elEff = wordToInt(LFile.TabWords[0]);
    for(int i=0;i<listResep.elEff;i++){
        ADVNewline();
        LFile = readLineFile();
        
        Tree parent = newTreeNode(wordToInt(LFile.TabWords[0]));
        int bykChild = wordToInt(LFile.TabWords[1]);
        for(int j=0;j<bykChild;j++){
            addChild(&parent, wordToInt(LFile.TabWords[2+j]));
        }
        listResep.list[i] = parent;
        // printPreorder(parent);
        // printf("\n");
    }
}