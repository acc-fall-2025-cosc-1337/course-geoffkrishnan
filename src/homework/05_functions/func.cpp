#include "func.h"
#include <stdexcept>

using std::invalid_argument;


string get_dna_complement(string dna) {
    if (dna.empty()) {
        throw invalid_argument("DNA sequence is empty.");
    }

    for (auto c: dna) {
        if (c!= 'A' && c!= 'T' && c!= 'G' && c!= 'C') {
            throw invalid_argument("Invalid DNA character in sequence. Only A, T, G, C allowed.");
        } 
    }

    //A ↔ T, G ↔ C
    for (auto &c : dna) {
        switch(c) {
            case 'A': c = 'T'; break;
            case 'T': c = 'A'; break;
            case 'C': c = 'G'; break;
            case 'G': c = 'C'; break;
        }
    }

    return reverse_string(dna);
}


string reverse_string(string dna) {
    int end_index = dna.length(); 
    char temp;
    
    for (int i = 0; i < dna.length()/2; i++) {
        temp = dna[i];
        dna[i] = dna[end_index - (i + 1)];
        dna[end_index - (i + 1)] = temp;
    }

    return dna;
} 

double get_gc_content (const string& dna) {
    if (dna.empty()) {
        throw invalid_argument("DNA sequence is empty.");
    }

    for (const auto& c: dna) {
        if (c!= 'A' && c!= 'T' && c!= 'G' && c!= 'C') {
            throw invalid_argument("Invalid DNA character in sequence. Only A, T, G, C allowed.");
        } 
    }


    double gc_count = 0;

    for (const auto &c : dna) {
        if (c == 'G' || c == 'C') {
           gc_count++; 
        }
    }

    return gc_count/dna.length();
}

