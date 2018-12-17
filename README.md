Our goal is to identify similarities between documents. We say that two documents are similar if they contain a significant number of common substrings that are not too small. 

The problem of computing the similarity between two files has been studied extensively and many programs have been developed to solve it. Algorithms for the problem have numerous applications, including spelling correction systems, file comparison tools or even the study of genetic evolution.

 Existing approaches can also include a brute force approach of comparing all sub-strings of pair of documents. However, such and approach is computationally prohibitive. 

We have used the Jaccard Similarity theorem,  *Local-Sensitive Hashing* algorithm and a *k-shingles* and *minhash signatures* representation of documents to evaluate the effectivity of the similarity computed and the time of computation. We have introduced three different hash functions to see its differences in performance.  Also once determined the best parameters, we will give a conclusion about the best way to identify the more similar documents. 


## Compiling

   To make easier the work of compiling end executing the source files we have created a makefile that can be seen in our source folder. Inside the makefile we have determined several functionalities that can help us in the task of compiling our source files:

- **Default option**: it compiles all our source files and generates all our executables. It also creates several object files in order to be able to generate some of our executables. 
  To run it you have to type:``` make ```
- **Delete all the object and executables files** generated in the folder:
  To run it you have to type: ```make clean```

## Executing

After using the makefile to compile our files we can execute them.

- Execute the program where **you can try all of our implemented functionalities** by answering the questions that are prompted:
  To run it you have to type: ```./mainDriver```
- Execute the program that **compares two different documents using Jaccard Similarity**:
  To run it you have to type: ```./compjac```
- Execute the program that generates **permutations** of a file:
  To run it you have to type: ```./permutacions```
- Execute the program that creates the data for our **Performance of Different Hashing Algorithms** experiment:
  To run it you have to type:```./jocProvesHashTimes```
- Execute the program that creates the data for our **Performance of Different Document Similarity Approaches** experiment:
  To run it you have to type: ```./jocProvesJaccSimLsh```
- Execute the program that creates the data for our **Precision of Jaccard Similarity Approximations** experiment:
  To run it you have to type: ```./jocProvesJaccSim```
