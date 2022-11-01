// #include "stdio.h"
// #include "wordmachine.h"
// #include "tree.h"
// #include "../liststatik/liststatikT.h"

// void tambahBahan(Tree *parent, Tree child){
//     if((*parent)->info==child->info && (*parent)->childEff==0){
//         for(int i=0;i<child->childEff;i++){
//             addChild(parent, child->children[i]);
//         }
//     }else{
//         for(int i=0;i<(*parent)->childEff;i++){
//             tambahBahan(&(*parent)->children[i],child);
//         }
//     }
// }

// int main(){
//     Word dir = {"../../../config/resep/configresep.txt", 37};

//     STARTWORDFILE(dir.TabWord);
//     ListWord LFile;
//     createListWord(&LFile);
//     LFile = readLineFile();
    

//     ListStatikT listResep;
//     listResep.elEff = 0;
//     listResep.elEff = wordToInt(LFile.TabWords[0]);
//     for(int i=0;i<listResep.elEff;i++){
//         ADVNewline();
//         LFile = readLineFile();
        
//         Tree parent = newTreeNode(wordToInt(LFile.TabWords[0]));
//         int bykChild = wordToInt(LFile.TabWords[1]);
//         for(int j=0;j<bykChild;j++){
//             addChild(&parent, newTreeNode(wordToInt(LFile.TabWords[2+j])));
//         }
//         listResep.list[i] = parent;
//         for(int j=0;j<i;j++){
//             tambahBahan(&parent, listResep.list[j]);
//             tambahBahan(&listResep.list[j], parent);
//         }
//     }

//     for(int i=0;i<listResep.elEff;i++){
//         printPreorder(listResep.list[i]);
//         printf("\n");
//     }
// }