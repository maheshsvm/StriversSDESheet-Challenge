#include <bits/stdc++.h> 

class TrieNode{

   public:

   TrieNode*children[26];

   int endwith;

   int countprefix;

   TrieNode(){

       endwith = 0;

       countprefix = 0;

       for(int i = 0 ; i < 26 ; i++){

           children[i] = NULL;

       }

   }

};

class Trie{

    private:

      TrieNode*root;

    public:

 

    Trie(){

        root = new TrieNode();

    }

    

    void InsertWord(TrieNode*root , string word){

        // Base Case

        if(word.length() == 0){

             root->countprefix++;

             root->endwith++;

             return;

        }

 

         // Small-Calulation 

          int index = word[0] - 'a';

          TrieNode*child;

          if(root->children[index] != NULL){

              child = root->children[index];

             

 

          }

          else{

              TrieNode*newTrieNode = new TrieNode();

              root->children[index] = newTrieNode;

              child = root->children[index];

              

          }

          root->countprefix++;

          // Recursive Call

          InsertWord(child , word.substr(1));

    }

   int CountWords(TrieNode*root , string word){

        if(word.length() == 0){

            return root->endwith;

        }

        

        // Small-Calculation

         int index = word[0]-'a';

         TrieNode*child;

         if(root->children[index] != NULL){

            child = root->children[index];

         }

         else{

             return 0;

         }

 

         // RecursivE cALL

         return CountWords(child , word.substr(1));

   }

   int CountWord_withPrefix(TrieNode*root , string word){

        

        // Base Case

         if(word.length() == 0){

              return root->countprefix;

         }

        // Small Calculation

        int index = word[0] - 'a';

        TrieNode*child;

        if(root->children[index] != NULL){

            child = root->children[index];

        }

        else{

            return 0;

        }

 

        // recursive Call

        return CountWord_withPrefix(child , word.substr(1));

   }

   void RemoveWords(TrieNode*root , string word){

       // Base Case

       if(word.length() == 0){

            root->countprefix--;

            root->endwith--;

           return;

       }

 

       // SmallCalculation

        int index = word[0] - 'a';

        TrieNode*child;

        if(root->children[index] != NULL){

              root->countprefix--;

              child = root->children[index];

        }

        else{

             return;

        }

 

        // Recursive Call

        RemoveWords(child, word.substr(1));

 

        

        

 

         

   }

   void insert(string &word){

        InsertWord(root , word);

    }

 

    int countWordsEqualTo(string &word){

          return CountWords(root , word);

    }

 

    int countWordsStartingWith(string &word){

        return CountWord_withPrefix(root , word);

    }

 

    void erase(string &word){

         RemoveWords(root , word);

    }

};