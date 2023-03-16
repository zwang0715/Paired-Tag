//
// Created by Chenxu Zhu on 6/29/18.
//

#ifndef REACHTOOLS_REACHTOOLS_H
#define REACHTOOLS_REACHTOOLS_H

#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "cxstring.h"

using namespace std;



class reachtools {
private:

public:
    static string extract_barcode(string seq); //, map<string, string> bc_library);
    static void docking(string & seq, string & quality); //, map<string, string> bc_library)
};

class bc_library {
public:
	vector<string> lib1;
	vector<string> lib2;
	vector<string> lib3;
	string type;
	void init(){
	  lib1 = {"AAACAAC","AAACCGG","AAACGTC","AAAGATG","AAATCCA","AAATGAG",
	  "AACACTG","AACGTTT","AAGAAGC","AAGCCCT","AAGCTAC","AATCTTG","ACAACAC",
	  "ACAGTAT","ACCAAGT","ACCCTAA","ACCCTTT","ACCTCTC","ACGATTG","ACGCAGA",
	  "ACGTAAA","ACTACCT","ACTCGGT","ACTGTCG","ACTTATG","AGAAAGG","AGAATCT",
	  "AGACATA","AGAGACC","AGCCCAA","AGCTATT","AGGAGGT","AGGGCTT","AGGTGTA",
	  "AGTGCTC","AGTGGGA","AGTTACG","ATAAGGG","ATCATTC","ATGGAAC","ATGTGCC",
	  "ATTCACC","ATTCGAG","CAAGCCT","CACAAGG","CACCTTA","CAGAGTG","CAGCGAA",
	  "CAGGTCA","CATAACT","CATATCG","CATCGAT","CATTACA","CATTTCC","CCAAATG",
	  "CCACTTG","CCGGATA","CCGGTTT","CCTAAGA","CCTAGTC","CCTGCAA","CGACGTT",
	  "CGAGTAA","CGATTAT","CGTAGCA","CGTCTGA","CTACAGC","CTCAATA","CTCGTTG",
	  "CTCTACG","CTTGGGT","GAAACTC","GACTGTC","GATACAG","GCGATCA","GCGTACT",
	  "GCTCGAA","GGAAGAA","GGAGATT","GGGCTAA","GGGTATG","GGTAACC","GGTAGTG",
	  "GGTGAAA","GTAATCG","GTATAAG","GTCAGAC","GTCCCTT","GTGCCAT","GTGGTCT",
	  "GTTCTCC","GTTGCTT","TACCCGA","TAGACGA","TAGTCAC","TCACATC"};
	  lib3 = {"AAACAAAC","AAACACGG","AAACACTA","AAACCGCC","AAACGATC","AAACGTGA","AAACTACA","AAACTGTG","AAAGAAAG","AAAGAGGC","AAAGCCCG","AAAGTCAT","AAATAGCA","AAATTCCG","AACAAATG","AACAGAAC","AACAGCGG","AACGATTT","AACGCCAA","AACGGTAG","AACGTTAC","AACTCAGT","AACTGCCT","AAGAACAG","AAGAAGGT","AAGAGTAT","AAGCCTTC","AAGCTCCT","AAGGATGA","AAGGCGCT","AAGGGACC","AAGTATTG","AAGTCCAA","AAGTCGGG","AAGTGAGA","AAGTTGTC","AATAAGGA","AATACATC","AATATGAC","AATCCGGC","AATCGAAG","AATCGTTC","AATGGCGT","AATGTATG","ACAAAGAT","ACAAGTAG","ACAATCTT","ACACCAAG","ACAGATAA","ACAGGCCA","ACATCTCG","ACATGGAC","ACCAACCC","ACCAAGGG","ACCACAGA","ACCAGTTT","ACCCATGC","ACCCGATT","ACCCTCAA","ACCGTCGA","ACCTGAAG","ACCTTCCC","ACGAATTC","ACGACGAC","ACGCTTAA","ACGGAGCA","ACGGCAGT","ACGGGTTA","ACGGTTGG","ACGTAAAC","ACTAATTG","ACTACCCG","ACTAGAGC","ACTCATAC","ACTCGGAA","ACTGCTGG","ACTGGTCA","ACTTCGCT","AGAAACCA","AGAAAGTG","AGAAGCTT","AGAATCAA","AGACCTCA","AGACGAGG","AGAGAGAC","AGAGGTGC","AGCAACGC","AGCACGTA","AGCATGCC","AGCCATCT","AGCGTGGT","AGCTCCAC","AGCTTCGA","AGGACACA","AGGAGTCG","AGGCAATA","AGGCCGAA","AGGCGTTT","AGGGACTG","AGGGTAAA","AGGTAAGC","AGGTATAT","AGGTTCCC","AGTAATGG","AGTAGTTA","AGTCACAA","AGTCCGTG","AGTGCTTC","AGTTGAAC","AGTTGCGG","AGTTTGTA","ATAACAGG","ATAAGCTA","ATACACCC","ATACTCTC","ATAGATGT","ATATGCAA","ATATGGGT","ATCAATCG","ATCAGGGA","ATCCCACC","ATCCGCAT","ATCCTAGT","ATCGCGCT","ATCGTAAC","ATCTTGGC","ATGACAAC","ATGACTTG","ATGCATAT","ATGCGGAG","ATGGGCTC","ATGGTCTG","ATGTGCCG","ATTACCTT","ATTATTCG","ATTCTGAG","ATTGAAGT","ATTGGCCC","ATTTCCAT","ATTTGTTG","CAAACATT","CAACGCAG","CAAGGAAT","CAAGGGTT","CAAGGTAC","CAATCTAG","CAATTCTC","CACAACCT","CACAAGTA","CACTAACC","CACTTGAT","CAGACTCG","CAGATGGG","CAGGTTGC","CAGTTTAA","CATGACGA","CATGCTGC","CATTCATT","CATTCGGG","CATTTCTA","CCACCTCT","CCACGTTG","CCAGACAG","CCAGCGAA","CCATATGA","CCATCCAC","CCATCGTC","CCATGCAT","CCCGTAAG","CCCGTTCT","CCCTCTTG","CCCTGTTT","CCCTTGCA","CCGACTTT","CCGAGATC","CCGATACG","CCGGAAAT","CCGTAGCT","CCGTCTTA","CCTACGCT","CCTATTTA","CCTCATGA","CCTTTACA","CCTTTGTC","CGAAACTC","CGAACCGA","CGAAGAAG","CGACATTT","CGAGGCTA","CGATCCAA","CGATGGCA","CGGACTAA","CGGCTGTA","CGGTGAGT","CGTACCGA","CGTCGAAT","CGTGCAAC","CGTGGGAT","CGTGTACA","CGTGTGTT","CGTTGCCT","CGTTTCGT","CTAACGCC","CTACGGGA","CTAGACTA","CTAGCACG","CTAGTAGG","CTCAAACA","CTCACATC","CTCCCAAA","CTCCTCCA","CTCGGTGA","CTCTATAG","CTCTGCGT","CTGAAGGG","CTGAGCGT","CTGCGATG","CTGCTAGA","CTGGAACA","CTGGGTAT","CTGTCGCA","CTGTGACC","CTGTTAAA","CTGTTGTG","CTGTTTCC","CTTAGGCC","CTTAGTGT","CTTCTACG","CTTTATCC","CTTTCACT","CTTTGGAC","GAAAGACA","GAAATACG","GAAGATAT","GAATCCCA","GAATGCGC","GACACAAA","GACACCTG","GACTAGCG","GAGAAACC","GAGCGGAA","GAGGAGTG","GAGGGTCA","GAGTGTAC","GATACGCA","GATGCAGA","GATGGTTA","GATGTGGC","GATTAAAG","GATTACTT","GATTGGGA","GATTTCCC","GCAAACTG","GCACTCAG","GCATCACT","GCATCGAG","GCCAAAGC","GCCAACAT","GCCTGGTA","GCCTTGTG","GCGCTGAT","GCGGTAAC","GCGTATTC","GCGTGCAA","GCTAAGTT","GCTACCGT","GCTATGGG","GCTCGTAG","GCTTCTCC","GGAACGAA","GGAAGTCC","GGACTGGA","GGACTTCT","GGAGGTTT","GGAGTAAG","GGATTGTT","GGCAAGGT","GGCACTTC","GGCCCAAT","GGCGACAA","GGCTATAA","GGCTTTGC","GGGAGATG","GGGATTAC","GGGCATCA","GGGTCATT","GGGTCTAG","GGTAAATC","GGTAGCCA","GGTCCTAA","GGTCTTTC","GGTGTCGA","GGTTACAC","GGTTAGGG","GGTTGAGA","GTAAACAA","GTAAGCCG","GTAATCTG","GTACGCTT","GTACGGAC","GTATACGT","GTATTGAC","GTCAAGAG","GTCAGACC","GTCAGGTT","GTCCACTA","GTCCGTCA","GTCCTTGC","GTCTAATC","GTCTGGAA","GTCTTCCT","GTGAACTC","GTGAGGCA","GTGATAAA","GTGCCCAT","GTGCGAAG","GTGGTGCT","GTGTCACC","GTGTCAGG","GTTACTAG","GTTCTGCT","GTTGTCCG","TAAACCGA","TAACTTCT","TAAGGGCC","TAATCCAT","TAATGTGG","TACCCTGC","TACCGCTC","TACCTAAG","TACCTCCC","TACGCGAG","TACGTTCG","TACTGAAT","TAGATCAA","TAGCCACA","TAGCGGAT","TAGGCTTT","TAGGTACG","TAGTAGCC","TAGTCTCT","TATCCACG","TATCTGTC","TATGTGAA","TATTAGCG","TCAAATGG","TCAAGGCG","TCAGCCTC","TCATACCA","TCATAGCT","TCATTTCA","TCCAGAAG","TCCCTGGA","TCCGACAC","TCCGCTGT","TCCTATAT","TCGACTGC","TCGAGTTT","TCGCAATC","TCGGTCAT","TCGTGGGT","TCGTTCCC","TCTAAACT","TCTATTCC","TCTGATTT","TCTTTGAC","TGAATAGG","TGAATCCT","TGACGTCG","TGAGAGCG","TGAGCACA","TGCACCAG","TGCCGGTA","TGCGACTA","TGCTGACG","TGCTTCAT","TGCTTGGG","TGGAAAGC","TGGACGGA","TGGCTAGT","TGGGAATT","TGGTGTCT","TGGTTAAC","TGTTATCA","TGTTCGCT","TTAACGTT","TTAGCAAT","TTAGCTGC","TTATATCG","TTATGACC","TTCACTGG","TTCCCTAT","TTCGAGCC","TTCGTTAT","TTCTAGGA","TTCTCGCG","TTGACCCA","TTGCATTC","TTGCTCTA","TTGGAGAC","TTGGGTCC","TTGTGCGG","TTTAGAAC","TTTCAGGT","TTTGCCAG","TTTGGCAT","TTTGTACA"}; //now don't use this one...
		lib2 = {"CATC", "ATGA", "AGCT", "ACAG", "GAAT","TACG","TTAC","GTTG","CCGT","CGAA","TCTA","GGGC"};
		return;
	}
};

class read2 {
private:
	int align_score(string str1, string str2){
		int score = 0;
    for(int i = 0; i < str1.length(); ++i){
      if(str2[i] == 'N')continue;
      str2[i] == str1[i] ? (score += 2) : (score -= 1);
      //if(str2[i] == str1[i]){
      //	++score;
      //}

    }
    return score;
	}
public:
	int bc1, bc2, bc3, bc4;
	string bc, rawline, sbc1, sbc2, sbc3, sbc4, bsbc4, type, umi;
	int dock;
	bool valid;

	void init(string line){
		rawline = line;
		dock = -1;
		valid = false;
		return;
	}

	void trim(){
		// NNNNNNNNNNNNNNNNNGTGGCCGATGTTTCGCATCGGCGTACGACTNNNNNNNGGATTCGAGGAGCGTGTGCGAACTCAGACCNNNNNNNATCCACGTGCTTGAGAGGCCAGAGCATTCGNNNNNNN
		// 1 determine additional Ns

		if(rawline.length() < 125)return;
		dock = 0;
		int t = 0;
		int cur_s = 0;
		string bait = "GTGGCCGATGTTTCG";
		for(int i = -2; i < 7; ++i){
			string qu = rawline.substr(17+i, 15);
			int score = align_score(qu, bait);
			if(score < cur_s)continue;
			cur_s = score;
			t = i;
		}
		//if(cur_s<15)return;
		if(cur_s<3)return;
		dock = 1;
		sbc1 = rawline.substr(10, 7);
		umi = rawline.substr(0, 10);
		if(t==-1){
			umi = "N" + rawline.substr(0, 9);
		}
		else if(t==-2){
			umi = "NN" + rawline.substr(0, 8);
		}

		//2nd bc
		bait = "GGATTCGAGGAGCGT";
		cur_s = 0;
		int tt = t;
		for(int i = -2; i < 3; ++i){
			string qu = rawline.substr(54+i+tt, 15);
			int score = align_score(qu, bait);
			if(score < cur_s)continue;
			cur_s = score;
			tt = t + i;
		}
		//if(cur_s<13)return;
		if(cur_s<2)return;
		t = tt;
		sbc2 = rawline.substr(47+t, 7);
		dock = 2;

		//3rd bc
		bait = "ATCCACGTGCTTGAG";
		cur_s = 0;
		for(int i = -2; i < 3; ++i ){
			string qu = rawline.substr(91+i+tt, 15);
			int score = align_score(qu, bait);
			if(score < cur_s)continue;
			cur_s = score;
			tt = t + i;
		}
		if(cur_s<2)return;
		t = tt;
		sbc3 = rawline.substr(84+t, 7);
		dock = 3;

		//4th BC
		bait = "AGGCCAGAGCATTCG";
		cur_s = 0;
		for(int i = -2; i < 3; ++i ){
			string qu = rawline.substr(106+i+tt, 15);
			int score = align_score(qu, bait);
			if(score < cur_s)continue;
			cur_s = score;
			tt = t + i;
		}
		//if(cur_s<9)return;
		if(cur_s<1)return;
		t = tt;
		if(rawline.length() < 126+t)return;
		sbc4 = rawline.substr(123+t, 3);
		bsbc4 = rawline.substr(119+t, 7);
		dock = 4;		
		// determine type
		// DNA TC
		// RNA AG
		cur_s = 0;
		string b1 = rawline.substr(121+t, 1);
		string b2 = rawline.substr(122+t, 1);
		if(b1 == "A")cur_s++;
		if(b1 == "T")cur_s--;
		if(b2 == "G")cur_s++;
		if(b2 == "C")cur_s--;
		if(cur_s > 0){
			type = "d";
		}
		else if(cur_s < 0){
			type = "r";
		}
		else{
			type = "n";
		}
		return;
	}

	void extract_barcode(bc_library lib, int score1, int score2){
		bool v1,v2,v3,v4 = false;
		if(dock <7 ) return;
		//bc#1
		bc1 = 0;
		int score = score1;
		int cur_score = 0;
		for(int i = 0; i < 96; ++i){
			cur_score = align_score(sbc1, lib.lib1[i]);
			if(cur_score < score){
				continue;
			}
			//else if(cur_score == score){
			//	v1 = false;
			//}
			else{
				v1 = true;
				score = cur_score;
				bc1 = i;
			}
		}
		if(!v1){
			bc1 = 0;
			bc = "00:";
		}
		else{
			if(bc1 < 9){
				bc1++;
				bc = "0" + cxstring::int2str(bc1) + ":";
			}
			else{
				bc1++;
				bc = cxstring::int2str(bc1) + ":";
			}
		}
		//bc#2
		bc2 = 0;
		score = score1;
		for(int i = 0; i < 96; ++i){
			cur_score = align_score(sbc2, lib.lib1[i]);
			if(cur_score < score){
				continue;
			}
			//else if(cur_score == score){
			//	v2 = false;
			//}
			else{
				v2 = true;
				score = cur_score;
				bc2 = i;
			}
		}
		if(!v2){
			bc2 = 0;
			bc = bc + "00:";
		}
		else{
			if(bc2 < 9){
				bc2++;
				bc = bc + "0" + cxstring::int2str(bc2) + ":";
			}
			else{
				bc2++;
				bc = bc + cxstring::int2str(bc2) + ":";
			}
		}
		//bc#3
		bc3 = 0;
		score = score1;
		for(int i = 0; i < 96; ++i){
			cur_score = align_score(sbc3, lib.lib1[i]);
			if(cur_score < score){
				continue;
			}
			//else if(cur_score == score){
			//	v3 = false;
			//}
			else{
				v3 = true;
				score = cur_score;
				bc3 = i;
			}
		}
		if(!v3){
			bc3 = 0;
			bc = bc + "00:";
		}
		else{
			if(bc3 < 9){
				bc3++;
				bc = bc + "0" + cxstring::int2str(bc3) + ":";
			}
			else{
				bc3++;
				bc = bc + cxstring::int2str(bc3) + ":";
			}
		}

		//bc#4
		bc4 = 0;
		score = score2;
		for(int i = 0; i < 8; ++i){
			cur_score = align_score(sbc4, lib.lib2[i]);
			if(cur_score < score){
				continue;
			}
			//else if(cur_score == score){
			//	v4 = false;
			//}
			else{
				v4 = true;
				score = cur_score;
				bc4 = i;
			}
		}
		if(!v4){
			bc4 = 0;
			bc = bc + "00";
		}
		else{
			bc4++;
			bc = bc + "0" + cxstring::int2str(bc4);
		}

		valid = v1&&v2&&v3&&v4;
		return;
	}


	void extract_barcode_4(int score2){
		if(dock <4 ) return;
		int score = 0;
		int cur_score = 0;
		bool v4=false;
		vector<string> lib2;
		lib2 = {"ATC", "TGA", "GCT", "CAG", "AGA","TCT","GAG","CTC"};
		
		//bc#4
		bc4 = 0;
		score = score2;
		for(int i = 0; i < 8; ++i){
			cur_score = align_score(sbc4, lib2[i]);
			if(cur_score < score){
				continue;
			}
			else{
				v4 = true;
				score = cur_score;
				bc4 = i;
			}
		}

		if(!v4){
			bc4 = 0;
		}
		else{
			bc4++;
		}

		return;
	}



	bool is_valid(){
		return valid;
	}
	int where_dock(){
		return dock;
	}
};

class read2_2r {
private:
	int align_score(string str1, string str2){
		int score = 0;
    for(int i = 0; i < str1.length(); ++i){
      if(str2[i] == 'N')continue;
      str2[i] == str1[i] ? (score += 2) : (score -= 1);
    }
    return score;
	}
	
public:
	int bc1, bc2, bc4;
	string bc, rawline, sbc1, sbc2, sbc4, bsbc4, type, umi;
	int dock;
	bool valid;

	void init(string line){
		rawline = line;
		dock = -1;
		valid = false;
		return;
	}

	void trim(){
		// nnnnNNNNNNNNNNNNNNNNNGTGGCCGATGTTTCGGTGCGAACTCAGACCNNNNNNNATCCACGTGCTTGAGAGGCCAGAGCATTCGXXNNNNN
		//".   NNNNNNNNNNNNNNNNNGTGGCCGATGTTTCGGTGCGAACTCAGACCNNNNNNNATCCACGTGCTTGAGAGGCCAGAGCATTCGXNNNNYY";
		// 1 determine additional Ns

		if(rawline.length() < 95)return;
		dock = 0;
		int t = 0;
		int cur_s = 10;
		string bait = "GTGGCCGATGTTTCG";
		for(int i = -2; i < 7; ++i){
			string qu = rawline.substr(17+i, 15);
			int score = align_score(qu, bait);
			if(score < cur_s)continue;
			cur_s = score;
			t = i;
		}
		//if(cur_s<15)return;
		if(cur_s<13)return;
		dock = 1;
		sbc1 = rawline.substr(10, 7);
		umi = rawline.substr(0, 10);
		if(t==-1){
			umi = "N" + rawline.substr(0, 9);
		}
		else if(t==-2){
			umi = "NN" + rawline.substr(0, 8);
		}

		//2nd bc
		bait = "ATCCACGTGCTTGAG";
		cur_s = 10;
		int tt = t;
		for(int i = -2; i < 3; ++i){
			string qu = rawline.substr(54+i+tt, 15);
			int score = align_score(qu, bait);
			if(score < cur_s)continue;
			cur_s = score;
			tt = t + i;
		}
		//if(cur_s<13)return;
		if(cur_s<12)return;
		t = tt;
		sbc2 = rawline.substr(47+t, 7);
		dock = 2;

		//4th BC
		bait = "AGGCCAGAGCATTCG";
		cur_s = 10;
		for(int i = -2; i < 3; ++i ){
			string qu = rawline.substr(69+i+tt, 15);
			int score = align_score(qu, bait);
			if(score < cur_s)continue;
			cur_s = score;
			tt = t + i;
		}
		//if(cur_s<9)return;
		if(cur_s<11)return;
		t = tt;
		if(rawline.length() < 89+t)return;
		//sbc4 = rawline.substr(86+t, 3);
		sbc4 = rawline.substr(85+t, 4);
		//bsbc4 = rawline.substr(82+t, 7);
		dock = 4;		
		//determine type
		cur_s = 0;
		string b1 = rawline.substr(84+t, 1);
		string b2 = rawline.substr(89+t, 1);
		if(b1 == "A")cur_s++;
		if(b1 == "T")cur_s--;
		if(b2 == "G")cur_s++;
		if(b2 == "C")cur_s--;
		if(cur_s > 0){
			type = "d";
		}
		else if(cur_s < 0){
			type = "r";
		}
		else{
			type = "n";
		}
		//type= "a";
		return;
	}

	void extract_barcode(bc_library lib, int score1, int score2){
		bool v1,v2,v4 = false;
		if(dock <7 ) return;
		//bc#1
		bc1 = 0;
		int score = score1;
		int cur_score = 0;
		for(int i = 0; i < 96; ++i){
			cur_score = align_score(sbc1, lib.lib1[i]);
			if(cur_score < score){
				continue;
			}
			//else if(cur_score == score){
			//	v1 = false;
			//}
			else{
				v1 = true;
				score = cur_score;
				bc1 = i;
			}
		}
		if(!v1){
			bc1 = 0;
			bc = "00:";
		}
		else{
			if(bc1 < 9){
				bc1++;
				bc = "0" + cxstring::int2str(bc1) + ":";
			}
			else{
				bc1++;
				bc = cxstring::int2str(bc1) + ":";
			}
		}
		//bc#2
		bc2 = 0;
		score = score1;
		for(int i = 0; i < 96; ++i){
			cur_score = align_score(sbc2, lib.lib1[i]);
			if(cur_score < score){
				continue;
			}
			//else if(cur_score == score){
			//	v2 = false;
			//}
			else{
				v2 = true;
				score = cur_score;
				bc2 = i;
			}
		}
		if(!v2){
			bc2 = 0;
			bc = bc + "00:";
		}
		else{
			if(bc2 < 9){
				bc2++;
				bc = bc + "0" + cxstring::int2str(bc2) + ":";
			}
			else{
				bc2++;
				bc = bc + cxstring::int2str(bc2) + ":";
			}
		}

		//bc#4
		bc4 = 0;
		score = score2;
		for(int i = 0; i < 8; ++i){
			cur_score = align_score(sbc4, lib.lib2[i]);
			if(cur_score < score){
				continue;
			}
			//else if(cur_score == score){
			//	v4 = false;
			//}
			else{
				v4 = true;
				score = cur_score;
				bc4 = i;
			}
		}
		if(!v4){
			bc4 = 0;
			bc = bc + "00";
		}
		else{
			bc4++;
			bc = bc + "0" + cxstring::int2str(bc4);
		}

		valid = v1&&v2&&v4;
		return;
	}


	void extract_barcode_4(int score2){
		if(dock <4 ) return;
		int score = 0;
		int cur_score = 0;
		bool v4=false;
		vector<string> lib2;
		lib2 = {"ATC", "TGA", "GCT", "CAG", "AGA","TCT","GAG","CTC"};
		
		//bc#4
		bc4 = 0;
		score = score2;
		for(int i = 0; i < 8; ++i){
			cur_score = align_score(sbc4, lib2[i]);
			if(cur_score < score){
				continue;
			}
			else{
				v4 = true;
				score = cur_score;
				bc4 = i;
			}
		}

		if(!v4){
			bc4 = 0;
		}
		else{
			bc4++;
		}

		return;
	}



	bool is_valid(){
		return valid;
	}
	int where_dock(){
		return dock;
	}
};

class read2_3r { //for 12*384*384bp BC
private:
	int align_score(string str1, string str2){
		int score = 0;
    for(int i = 0; i < str1.length(); ++i){
      if(str2[i] == 'N')continue;
      str2[i] == str1[i] ? (score += 2) : (score -= 1);
    }
    return score;
	}
	
public:
	int bc1, bc2, bc4;
	string bc, rawline, sbc1, sbc2, sbc4, bsbc4, type, umi;
	int dock;
	bool valid;

	void init(string line){
		rawline = line;
		dock = -1;
		valid = false;
		return;
	}

	void trim(){
		// nnnnNNNNNNNNNNNNNNNNNGTGGCCGATGTTTCGGTGCGAACTCAGACCNNNNNNNATCCACGTGCTTGAGAGGCCAGAGCATTCGXXNNNNN
		//".   NNNNNNNNNNNNNNNNNGTGGCCGATGTTTCGGTGCGAACTCAGACCNNNNNNNATCCACGTGCTTGAGAGGCCAGAGCATTCGXNNNNYY";
		// 1 determine additional Ns

		if(rawline.length() < 97)return;
		dock = 0;
		int t = 0;
		int cur_s = 10;
		string bait = "GTGGCCGATGTTTCG";
		for(int i = -2; i < 7; ++i){
			string qu = rawline.substr(18+i, 15);
			int score = align_score(qu, bait);
			if(score < cur_s)continue;
			cur_s = score;
			t = i;
		}
		//if(cur_s<15)return;
		if(cur_s<13)return;
		dock = 1;
		sbc1 = rawline.substr(10, 8);
		umi = rawline.substr(0, 10);
		if(t==-1){
			umi = "N" + rawline.substr(0, 9);
		}
		else if(t==-2){
			umi = "NN" + rawline.substr(0, 8);
		}

		//2nd bc
		bait = "ATCCACGTGCTTGAG";
		cur_s = 10;
		int tt = t;
		for(int i = -2; i < 3; ++i){
			string qu = rawline.substr(56+i+tt, 15);
			int score = align_score(qu, bait);
			if(score < cur_s)continue;
			cur_s = score;
			tt = t + i;
		}
		//if(cur_s<13)return;
		if(cur_s<12)return;
		t = tt;
		sbc2 = rawline.substr(48+t, 8);
		dock = 2;

		//4th BC
		bait = "AGGCCAGAGCATTCG";
		cur_s = 10;
		for(int i = -2; i < 3; ++i ){
			string qu = rawline.substr(71+i+tt, 15);
			int score = align_score(qu, bait);
			if(score < cur_s)continue;
			cur_s = score;
			tt = t + i;
		}
		//if(cur_s<9)return;
		if(cur_s<11)return;
		t = tt;
		if(rawline.length() < 89+t)return;
		//sbc4 = rawline.substr(86+t, 3);
		sbc4 = rawline.substr(87+t, 4);
		//bsbc4 = rawline.substr(82+t, 7);
		dock = 4;		
		//determine type

		cur_s = 0;
		string b1 = rawline.substr(86+t, 1);
		string b2 = rawline.substr(91+t, 1);
		if(b1 == "A")cur_s++;
		if(b1 == "T")cur_s--;
		if(b2 == "G")cur_s++;
		if(b2 == "C")cur_s--;
		if(cur_s > 0){
			type = "d";
		}
		else if(cur_s < 0){
			type = "r";
		}
		else{
			type = "n";
		}
		//type= "a";
		return;
	}

	void extract_barcode(bc_library lib, int score1, int score2){ // extract bc from list, rather than mapping?
		bool v1,v2,v4 = false;
		if(dock <7 ) return;
		//bc#1
		bc1 = 0;
		int score = score1;
		int cur_score = 0;
		for(int i = 0; i < 96; ++i){
			cur_score = align_score(sbc1, lib.lib1[i]);
			if(cur_score < score){
				continue;
			}
			//else if(cur_score == score){
			//	v1 = false;
			//}
			else{
				v1 = true;
				score = cur_score;
				bc1 = i;
			}
		}
		if(!v1){
			bc1 = 0;
			bc = "00:";
		}
		else{
			if(bc1 < 9){
				bc1++;
				bc = "0" + cxstring::int2str(bc1) + ":";
			}
			else{
				bc1++;
				bc = cxstring::int2str(bc1) + ":";
			}
		}
		//bc#2
		bc2 = 0;
		score = score1;
		for(int i = 0; i < 96; ++i){
			cur_score = align_score(sbc2, lib.lib1[i]);
			if(cur_score < score){
				continue;
			}
			//else if(cur_score == score){
			//	v2 = false;
			//}
			else{
				v2 = true;
				score = cur_score;
				bc2 = i;
			}
		}
		if(!v2){
			bc2 = 0;
			bc = bc + "00:";
		}
		else{
			if(bc2 < 9){
				bc2++;
				bc = bc + "0" + cxstring::int2str(bc2) + ":";
			}
			else{
				bc2++;
				bc = bc + cxstring::int2str(bc2) + ":";
			}
		}

		//bc#4
		bc4 = 0;
		score = score2;
		for(int i = 0; i < 8; ++i){
			cur_score = align_score(sbc4, lib.lib2[i]);
			if(cur_score < score){
				continue;
			}
			//else if(cur_score == score){
			//	v4 = false;
			//}
			else{
				v4 = true;
				score = cur_score;
				bc4 = i;
			}
		}
		if(!v4){
			bc4 = 0;
			bc = bc + "00";
		}
		else{
			bc4++;
			bc = bc + "0" + cxstring::int2str(bc4);
		}

		valid = v1&&v2&&v4;
		return;
	}


	void extract_barcode_4(int score2){
		if(dock <4 ) return;
		int score = 0;
		int cur_score = 0;
		bool v4=false;
		vector<string> lib2;
		lib2 = {"ATC", "TGA", "GCT", "CAG", "AGA","TCT","GAG","CTC"};
		
		//bc#4
		bc4 = 0;
		score = score2;
		for(int i = 0; i < 8; ++i){
			cur_score = align_score(sbc4, lib2[i]);
			if(cur_score < score){
				continue;
			}
			else{
				v4 = true;
				score = cur_score;
				bc4 = i;
			}
		}

		if(!v4){
			bc4 = 0;
		}
		else{
			bc4++;
		}

		return;
	}



	bool is_valid(){
		return valid;
	}
	int where_dock(){
		return dock;
	}
};

class read2_48r { // for 48 * 384 * 384
private:
	int align_score(string str1, string str2){
		int score = 0;
    for(int i = 0; i < str1.length(); ++i){
      if(str2[i] == 'N')continue;
      str2[i] == str1[i] ? (score += 2) : (score -= 1);
    }
    return score;
	}
	
public:
	int bc1, bc2, bc4;
	string bc, rawline, sbc1, sbc2, sbc4, bsbc4, type, umi;
	int dock;
	bool valid;

	void init(string line){
		rawline = line;
		dock = -1;
		valid = false;
		return;
	}

	void trim(){
		// nnnnNNNNNNNNNNNNNNNNNGTGGCCGATGTTTCGGTGCGAACTCAGACCNNNNNNNATCCACGTGCTTGAGAGGCCAGAGCATTCGXXNNNNNN
		//".   NNNNNNNNNNNNNNNNNGTGGCCGATGTTTCGGTGCGAACTCAGACCNNNNNNNATCCACGTGCTTGAGAGGCCAGAGCATTCGXNNNNNNYY";
		// 1 determine additional Ns

		if(rawline.length() < 98)return; // should be 95 + N
		dock = 0;
		int t = 0;
		int cur_s = 10;
		string bait = "GTGGCCGATGTTTCG";
		for(int i = -2; i < 7; ++i){
			string qu = rawline.substr(18+i, 15);
			int score = align_score(qu, bait);
			if(score < cur_s)continue;
			cur_s = score;
			t = i;
		}
		//if(cur_s<15)return;
		if(cur_s<13)return; 
		dock = 1;
		sbc1 = rawline.substr(10, 8);
		umi = rawline.substr(0, 10);
		if(t==-1){
			umi = "N" + rawline.substr(0, 9);
		}
		else if(t==-2){
			umi = "NN" + rawline.substr(0, 8);
		}

		//2nd bc
		bait = "ATCCACGTGCTTGAG";
		cur_s = 10;
		int tt = t;
		for(int i = -2; i < 3; ++i){
			string qu = rawline.substr(56+i+tt, 15);
			int score = align_score(qu, bait);
			if(score < cur_s)continue;
			cur_s = score;
			tt = t + i;
		}
		//if(cur_s<13)return;
		if(cur_s<12)return;
		t = tt;
		sbc2 = rawline.substr(48+t, 8);
		dock = 2;

		//4th BC
		bait = "AGGCCAGAGCATTCG";
		cur_s = 10;
		for(int i = -2; i < 3; ++i ){
			string qu = rawline.substr(71+i+tt, 15);
			int score = align_score(qu, bait);
			if(score < cur_s)continue;
			cur_s = score;
			tt = t + i;
		}
		//if(cur_s<9)return;
		if(cur_s<11)return;
		t = tt;
		if(rawline.length() < 89+t)return; // why?
		//sbc4 = rawline.substr(86+t, 3);
		sbc4 = rawline.substr(87+t, 5);
		//bsbc4 = rawline.substr(82+t, 7);
		dock = 4;		
		//determine type
		cur_s = 0;
		string b1 = rawline.substr(86+t, 1);
		string b2 = rawline.substr(92+t, 1);
		if(b1 == "A")cur_s++;
		if(b1 == "T")cur_s--;
		if(b2 == "G")cur_s++;
		if(b2 == "C")cur_s--;
		if(cur_s > 0){
			type = "d";
		}
		else if(cur_s < 0){
			type = "r";
		}
		else{
			type = "n";
		}
		return;
	}

	void extract_barcode(bc_library lib, int score1, int score2){
		bool v1,v2,v4 = false;
		if(dock <7 ) return;
		//bc#1
		bc1 = 0;
		int score = score1;
		int cur_score = 0;
		for(int i = 0; i < 96; ++i){
			cur_score = align_score(sbc1, lib.lib1[i]);
			if(cur_score < score){
				continue;
			}
			//else if(cur_score == score){
			//	v1 = false;
			//}
			else{
				v1 = true;
				score = cur_score;
				bc1 = i;
			}
		}
		if(!v1){
			bc1 = 0;
			bc = "00:";
		}
		else{
			if(bc1 < 9){
				bc1++;
				bc = "0" + cxstring::int2str(bc1) + ":";
			}
			else{
				bc1++;
				bc = cxstring::int2str(bc1) + ":";
			}
		}
		//bc#2
		bc2 = 0;
		score = score1;
		for(int i = 0; i < 96; ++i){
			cur_score = align_score(sbc2, lib.lib1[i]);
			if(cur_score < score){
				continue;
			}
			//else if(cur_score == score){
			//	v2 = false;
			//}
			else{
				v2 = true;
				score = cur_score;
				bc2 = i;
			}
		}
		if(!v2){
			bc2 = 0;
			bc = bc + "00:";
		}
		else{
			if(bc2 < 9){
				bc2++;
				bc = bc + "0" + cxstring::int2str(bc2) + ":";
			}
			else{
				bc2++;
				bc = bc + cxstring::int2str(bc2) + ":";
			}
		}

		//bc#4
		bc4 = 0;
		score = score2;
		for(int i = 0; i < 8; ++i){
			cur_score = align_score(sbc4, lib.lib2[i]);
			if(cur_score < score){
				continue;
			}
			//else if(cur_score == score){
			//	v4 = false;
			//}
			else{
				v4 = true;
				score = cur_score;
				bc4 = i;
			}
		}
		if(!v4){
			bc4 = 0;
			bc = bc + "00";
		}
		else{
			bc4++;
			bc = bc + "0" + cxstring::int2str(bc4);
		}

		valid = v1&&v2&&v4;
		return;
	}


	void extract_barcode_4(int score2){
		if(dock <4 ) return;
		int score = 0;
		int cur_score = 0;
		bool v4=false;
		vector<string> lib2;
		lib2 = {"ATC", "TGA", "GCT", "CAG", "AGA","TCT","GAG","CTC"};
		
		//bc#4
		bc4 = 0;
		score = score2;
		for(int i = 0; i < 8; ++i){
			cur_score = align_score(sbc4, lib2[i]);
			if(cur_score < score){
				continue;
			}
			else{
				v4 = true;
				score = cur_score;
				bc4 = i;
			}
		}

		if(!v4){
			bc4 = 0;
		}
		else{
			bc4++;
		}

		return;
	}



	bool is_valid(){
		return valid;
	}
	int where_dock(){
		return dock;
	}
};

class read2_pc2 {
private:
	int align_score(string str1, string str2){
		int score = 0;
    for(int i = 0; i < str1.length(); ++i){
      if(str2[i] == 'N')continue;
      str2[i] == str1[i] ? (score += 2) : (score -= 1);
//      str2[i] == str1[i] ? (score += 1) : (score -= 0);
      //if(str2[i] == str1[i]){
      //	++score;
      //}

    }
    return score;
	}
public:
	int bc1, bc2, bc4;
	string bc, rawline, sbc1, sbc2, sbc4, bsbc4, type, umi;
	int dock;
	bool valid;

	void init(string line){
		rawline = line;
		dock = -1;
		valid = false;
		return;
	}

	void trim(){
		// nnnnNNNNNNNNNNNNNNNNNGTGGCCGATGTTTCGGTGCGAACTCAGACCNNNNNNNATCCACGTGCTTGAGAGGCCAGAGCATTCGAXXXXNN
		//".   NNNNNNNNNNNNNNNNNGTGGCCGATGTTTCGGTGCGAACTCAGACCNNNNNNNATCCACGTGCTTGAGAGGCCAGAGCATTCGAGNNNYY";
		// 1 determine additional Ns

		if(rawline.length() < 93)return;
		dock = 0;
		int t = 0;
		int cur_s = 0;
		string bait = "GTGGCCGATGTTTCG";
		for(int i = -2; i < 7; ++i){
			string qu = rawline.substr(17+i, 15);
			int score = align_score(qu, bait);
			if(score < cur_s)continue;
			cur_s = score;
			t = i;
		}
		//if(cur_s<15)return;
		if(cur_s<3)return;
		dock = 1;
		sbc1 = rawline.substr(10, 7);
		umi = rawline.substr(0, 10);
		if(t==-1){
			umi = "N" + rawline.substr(0, 9);
		}
		else if(t==-2){
			umi = "NN" + rawline.substr(0, 8);
		}

		//2nd bc
		bait = "ATCCACGTGCTTGAG";
		cur_s = 0;
		int tt = t;
		for(int i = -2; i < 3; ++i){
			string qu = rawline.substr(54+i+tt, 15);
			int score = align_score(qu, bait);
			if(score < cur_s)continue;
			cur_s = score;
			tt = t + i;
		}
		//if(cur_s<13)return;
		if(cur_s<2)return;
		t = tt;
		sbc2 = rawline.substr(47+t, 7);
		dock = 2;

		//4th BC
		bait = "AGGCCAGAGCATTCG";
		cur_s = 0;
		for(int i = -2; i < 3; ++i ){
			string qu = rawline.substr(69+i+tt, 15);
			int score = align_score(qu, bait);
			if(score < cur_s)continue;
			cur_s = score;
			tt = t + i;
		}
		//if(cur_s<9)return;
		if(cur_s<1)return;
		t = tt;
		if(rawline.length() < 91+t)return;
		//sbc4 = rawline.substr(86+t, 3);
		sbc4 = rawline.substr(85+t, 6);
		//bsbc4 = rawline.substr(82+t, 7);
		dock = 4;		
		// determine type
		// DNA TC
		// RNA AG
		//cur_s = 0;
		//string b1 = rawline.substr(84+t, 1);
		//string b2 = rawline.substr(85+t, 1);
		//if(b1 == "A")cur_s++;
		//if(b1 == "T")cur_s--;
		//if(b2 == "G")cur_s++;
		//if(b2 == "C")cur_s--;
		//if(cur_s > 0){
		//	type = "d";
		//}
		//else if(cur_s < 0){
		//	type = "r";
		//}
		//else{
		//	type = "n";
		//}
		type= "a";
		return;
	}

	void extract_barcode(bc_library lib, int score1, int score2){
		bool v1,v2,v4 = false;
		if(dock <7 ) return;
		//bc#1
		bc1 = 0;
		int score = score1;
		int cur_score = 0;
		for(int i = 0; i < 96; ++i){
			cur_score = align_score(sbc1, lib.lib1[i]);
			if(cur_score < score){
				continue;
			}
			//else if(cur_score == score){
			//	v1 = false;
			//}
			else{
				v1 = true;
				score = cur_score;
				bc1 = i;
			}
		}
		if(!v1){
			bc1 = 0;
			bc = "00:";
		}
		else{
			if(bc1 < 9){
				bc1++;
				bc = "0" + cxstring::int2str(bc1) + ":";
			}
			else{
				bc1++;
				bc = cxstring::int2str(bc1) + ":";
			}
		}
		//bc#2
		bc2 = 0;
		score = score1;
		for(int i = 0; i < 96; ++i){
			cur_score = align_score(sbc2, lib.lib1[i]);
			if(cur_score < score){
				continue;
			}
			//else if(cur_score == score){
			//	v2 = false;
			//}
			else{
				v2 = true;
				score = cur_score;
				bc2 = i;
			}
		}
		if(!v2){
			bc2 = 0;
			bc = bc + "00:";
		}
		else{
			if(bc2 < 9){
				bc2++;
				bc = bc + "0" + cxstring::int2str(bc2) + ":";
			}
			else{
				bc2++;
				bc = bc + cxstring::int2str(bc2) + ":";
			}
		}

		//bc#4
		bc4 = 0;
		score = score2;
		for(int i = 0; i < 8; ++i){
			cur_score = align_score(sbc4, lib.lib2[i]);
			if(cur_score < score){
				continue;
			}
			//else if(cur_score == score){
			//	v4 = false;
			//}
			else{
				v4 = true;
				score = cur_score;
				bc4 = i;
			}
		}
		if(!v4){
			bc4 = 0;
			bc = bc + "00";
		}
		else{
			bc4++;
			bc = bc + "0" + cxstring::int2str(bc4);
		}

		valid = v1&&v2&&v4;
		return;
	}


	void extract_barcode_4(int score2){
		if(dock <4 ) return;
		int score = 0;
		int cur_score = 0;
		bool v4=false;
		vector<string> lib2;
		lib2 = {"ATC", "TGA", "GCT", "CAG", "AGA","TCT","GAG","CTC"};
		
		//bc#4
		bc4 = 0;
		score = score2;
		for(int i = 0; i < 8; ++i){
			cur_score = align_score(sbc4, lib2[i]);
			if(cur_score < score){
				continue;
			}
			else{
				v4 = true;
				score = cur_score;
				bc4 = i;
			}
		}

		if(!v4){
			bc4 = 0;
		}
		else{
			bc4++;
		}

		return;
	}



	bool is_valid(){
		return valid;
	}
	int where_dock(){
		return dock;
	}
};


class read2_assign {
private:
int dist(string X, string Y){
	int cost=0;
	int l = X.length();
	for(int i = 0; i < l; i++){
		if(X[i]!=Y[i]){cost++;}
	}
	return (cost);
}
bc_library lib;
public:
	int bc1, bc2, bc4;
	string bc, rawline, sbc1, sbc2, sbc4, bsbc4, type, umi;
	int dock;
	bool valid;

	void init(string line){
		rawline = line;
		dock = -1;
		valid = false;
		return;
	}

	void trim(){
		// nnnnNNNNNNNNNNNNNNNNNGTGGCCGATGTTTCGGTGCGAACTCAGACCNNNNNNNATCCACGTGCTTGAGAGGCCAGAGCATTCGXXNNNNN
		//".   NNNNNNNNNNNNNNNNNGTGGCCGATGTTTCGGTGCGAACTCAGACCNNNNNNNATCCACGTGCTTGAGAGGCCAGAGCATTCGXNNNNYY";
		// 1 determine additional Ns
		if(rawline.length() < 93)return;
		dock = 0;
		int t = 0;
		int cur_s = 10;
		string bait = "GTGGCCGATGTTTCG";

		for(int i = -2; i < 7; ++i){
			string qu = rawline.substr(17+i, 15);
			int score = dist(qu, bait);
			if(score > cur_s)continue;
			cur_s = score;
			t = i;
		}
		if(cur_s>10)return;
		dock = 1;
		sbc1 = rawline.substr(10, 7);
		umi = rawline.substr(0, 10);
		if(t==-1){
			umi = "N" + rawline.substr(0, 9);
		}
		else if(t==-2){
			umi = "NN" + rawline.substr(0, 8);
		}

		//2nd bc
		bait = "ATCCACGTGCTTGAG";
		cur_s = 10;
		int tt = t;
		for(int i = -2; i < 3; ++i){
			string qu = rawline.substr(54+i+tt, 15);
			int score = dist(qu, bait);
			if(score > cur_s)continue;
			cur_s = score;
			tt = t + i;
		}
		if(cur_s>10)return;
		t = tt;
		sbc2 = rawline.substr(47+t, 7);
		dock = 2;

		//4th BC
		bait = "AGGCCAGAGCATTCG";
		cur_s = 10;
		for(int i = -2; i < 3; ++i ){
			string qu = rawline.substr(69+i+tt, 15);
			int score = dist(qu,  bait);
			if(score > cur_s)continue;
			cur_s = score;
			tt = t + i;
		}
		//if(cur_s<9)return;
		if(cur_s>10)return;
		t = tt;
		if(rawline.length() < 89+t)return;
		sbc4 = rawline.substr(85+t, 4);
		dock = 4;		
		type= "a";
		return;
	}

	void extract_barcode(int score1, int score2){
		bool v1,v2,v4 = false;
		bc1 = 0;
		int score = score1;
		int cur_score = 5;
		bool exists_1 = false;
		for(int i = 0; i < 96; ++i){
			cur_score = dist(sbc1,  lib.lib1[i]);
			if(cur_score >= score){
				continue;
			}
			else{
				v1 = true;
				if(exists_1){v1 = false;};
				exists_1 = true;
				score = cur_score;
				bc1 = i;
			}
		}
		if(!v1){
			bc1 = 0;
			bc = "00:";
		}
		else{
			if(bc1 < 9){
				bc1++;
				bc = "0" + cxstring::int2str(bc1) + ":";
			}
			else{
				bc1++;
				bc = cxstring::int2str(bc1) + ":";
			}
		}
		//bc#2
		bc2 = 0;
		score = score1;
		cur_score=5;
		exists_1 = false;
		for(int i = 0; i < 96; ++i){
			cur_score = dist(sbc2,  lib.lib1[i]);
			if(cur_score > score){
				continue;
			}
			else{
				v2 = true;
				if(exists_1){v2=false;};
				exists_1 = true;
				score = cur_score;
				bc2 = i;
			}
		}
		if(!v2){
			bc2 = 0;
			bc = bc + "00:";
		}
		else{
			if(bc2 < 9){
				bc2++;
				bc = bc + "0" + cxstring::int2str(bc2) + ":";
			}
			else{
				bc2++;
				bc = bc + cxstring::int2str(bc2) + ":";
			}
		}

		//bc#4
		bc4 = 0;
		score = score2;
		cur_score = 5;
		exists_1 = false;

		for(int i = 0; i < 12; ++i){
			cur_score = dist(sbc4,  lib.lib2[i]);
			if(cur_score > score){
				continue;
			}
			else{
				v4 = true;
				if(exists_1){v4=false;};
				exists_1=true;
				score = cur_score;
				bc4 = i;
			}
		}
		if(!v4){
			bc4 = 0;
			bc = bc + "00";
		}
		else{
			bc4++;
			bc = bc + "0" + cxstring::int2str(bc4);
		}

		valid = v1&&v2&&v4;
		return;
	}


	void extract_barcode_4(int score2){
		if(dock <4 ) return;
		int score = 0;
		int cur_score = 0;
		bool v4=false;
		vector<string> lib2;
		lib2 = {"CATC", "ATGA", "AGCT", "ACAG", "GAAT","TACG","TTAC","GTTG","CCGT","CGAA","TCTA","GGGC"};
		
		//bc#4
		bc4 = 0;
		score = score2;
		for(int i = 0; i < 8; ++i){
			cur_score = dist(sbc4, lib2[i] );
			if(cur_score > score){
				continue;
			}
			else{
				v4 = true;
				score = cur_score;
				bc4 = i;
			}
		}

		if(!v4){
			bc4 = 0;
		}
		else{
			bc4++;
		}

		return;
	}



	bool is_valid(){
		return valid;
	}
	int where_dock(){
		return dock;
	}


};




#endif //REACHTOOLS_REACHTOOLS_H
