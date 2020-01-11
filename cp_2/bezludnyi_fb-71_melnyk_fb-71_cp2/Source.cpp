#include <iostream>
#include <fstream>
#include <string>

using namespace std;



void quickSort(double arr[], int arr2[], int left, int right) {

	int i = left, j = right;

	int tmp,ctmp;

	int pivot = arr[(left + right) / 2];
	while (i <= j) {

		while (arr[i] < pivot)

			i++;

		while (arr[j] > pivot)

			j--;

		if (i <= j) {

			ctmp = arr2[i];
			tmp = arr[i];

			arr2[i] = arr2[j];
			arr[i] = arr[j];

			arr2[j] = ctmp;
			arr[j] = tmp;

			i++;

			j--;

		}

	};
	if (left < j)

		quickSort(arr, arr2, left, j);

	if (i < right)

		quickSort(arr, arr2, i, right);

}


int mod(int k)
{
	int m = 32;
	if (k < m) 
	{
		if (k < 0) { for (;;) { k += m; if (k > 0) return k; } }
		return k;
	}
	else {
		for (;;)
		{
			k = k - m;
			if (k < m)return k;
		}
		cout << "\n\nk is " << k << "\n";
		return k;
	}
}

void copytext()
{
	ofstream output("output.txt");
	ifstream input("input.txt");
	ifstream inputee("inputee.txt");
	ofstream outputee("outputee.txt");

	string str = "", str1 = "";
	double IC = 0.055, TrueIC = .0;
	double tempIC = .0;
	int k = 2;
	double allnum = .0, h = 0;
	const int n = 32;
	
	char strLC[n] = { 'א', 'ב', 'ג', 'ד', 'ה', 'ו', 'ז', 'ח', 'ט', 'י', 'ך', 'כ', 'ל', 'ם', 'מ', 'ן', 'נ', 'ס', 'ע', 'ף', 'פ', 'ץ', 'צ', 'ק', 'ר', 'ש', 'ת', 'û', 'ü', '‎', '‏', 'ÿ' };
	string alph = "אבגדהוזחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ";
	double arr[n]; // symbol freq
	for (int i = 0; i < n; i++)
		arr[i] = .0;
	string str2 = "";
	
	

	int g = 0;
	getline(input, str);
	

	while (tempIC < IC && k < n)/////
	{
		
	
		for (int i = 0; i*k < str.length(); i++) /// divides text in subtexts based on key length
		{
			
			g = i * k;
			str1 += str[g]; // str1 subtext for step k
		}

		/

			for (int i = 0; i < str1.length(); i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (str1[i] == alph[j]) { arr[j]++; continue; }
				}

			}
			for (int i = 0; i < n; i++) // count number of symbols in text
				allnum += arr[i];

			for (int i = 0; i < n; i++)
				tempIC = tempIC + arr[i] * (arr[i] - 1) / (allnum * (allnum - 1));
				
			cout << "\nFor step " << k << " tempIC is " << tempIC<<endl;
			if (tempIC >= IC)
			{
				outputee << "\n\nThis is subtext freq\n";
				for (int i = 0; i < n; i++)
				{
					outputee << arr[i] * (arr[i] - 1) / (allnum * (allnum - 1))<< "\n";
				}
				

				cout << "\n\n\nFor step " << k << " tempIC : " << tempIC <<" is valid"<< endl;
///////// for true IC --start
				getline(inputee, str1);
				g = 0;
				
					for (int i = 0; i*k < str1.length(); i++)
					{
						g = i * k;
						str2 += str1[g];
					}
					
					for (int i = 0; i < n; i++)
					{
						arr[i] = 0;
					}
					allnum = .0;
					

					for (int i = 0; i < str2.length(); i++)
					{
						for (int j = 0; j < n; j++)
						{
							if (str2[i] == strLC[j]) { arr[j]++; continue; }
						}
					}
					
					for (int i = 0; i < n; i++) 
						allnum += arr[i];
					
					for (int i = 0; i < n; i++)
						TrueIC = TrueIC + arr[i] * (arr[i] - 1) / (allnum * (allnum - 1));
					
					cout << "\n\nTrue IC is : " << TrueIC << endl;

					outputee << "\n\nThis is Bigtext freq\n";
					for (int i = 0; i < n; i++)
					{
						outputee << arr[i] * (arr[i] - 1) / (allnum * (allnum - 1)) << "\n";
					}

//////////--end*/
				break;
			}
			k++;
			g = 0;
			tempIC = .0;
			if (k >= n) { cout << "\n\nError no k is found.."; break; }/////
			for (int i = 0; i < n; i++)
			{
				arr[i] = 0;
			}
			cout <<"\nallnum="<< allnum<<endl;
			allnum = .0;
			str1 = "";
			
	}


	
	
	if (k < n) { cout << "\n\n\nThe key length is " << k << "\n\n\n\n" << endl; }

	

	if (k < n) 
	{
		string substr[n], controlstr = "";
		int c = 0,a = 0;

		for (int i = 0; i < k ; i++)
		{
			substr[k] = "";
		}

		for (int i = 0; i < str.length(); i++) // divides text in subtexts
		{
			substr[i % k] += str[i];
		}

		for (int i = 0; i < k; i++)
		{
			output << substr[i] << "\n\n";
		}

		if (str.length() % k != 0) c = 1;
		a = str.length() / k + c;
		for(int j = 0; j < a ; j++)
		for (int i = 0; i < k; i++)//check
		{
			if (substr[i][j] != '\0') controlstr += substr[i][j];
		}

		output <<"\n\n\n" << controlstr<<"\n\n";
	
		double arrmax[n][n];
		int maxsymb[n][n];

		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arrmax[i][j] = .0;
				maxsymb[i][j] = 0;
			}
		}
		
		/////////////////// 
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < substr[i].length(); j++)
			{
				for (int l = 0; l < n; l++)//clear array for frequency count
					arr[l] = .0;
				for (int h = 0; h < substr[i].length(); h++)
				{
					for (int s = 0; s < n; s++)
					{
						if (substr[i][h] == strLC[s]) { arr[s]++; break; }
					}

				}
				

				for (int v = 0; v < n; v++)// find new highest frequecy symbol for subtext
					{ arrmax[i][v] = arr[v]; maxsymb[i][v] = v; }
			}
		}
		for (int i = 0; i < k; i++)
		{
			quickSort(&arrmax[i][0], &maxsymb[i][0], 0, n - 1);
			
				cout <<"\n-"<< maxsymb[i][31] << "--" <<  maxsymb[i][30] <<"--"<< maxsymb[i][29] << "for " <<"--" << alph[mod(maxsymb[i][31] - 14)]
																										 << "--" << alph[mod(maxsymb[i][30] - 14)]	
																							  			 << "--" << alph[mod(maxsymb[i][29] - 14)]<< "\n";
		}	
		cout << "\n";
		string key = "ןמסכוהםטיהמחמנ"; 
		int keyint[14]; // 14 is key length
		for (int i = 0; i < k; i++)
			for (int j = 0; j < n; j++)
			{
				if (key[i] == alph[j]) { keyint[i] = j; cout << keyint[i] << " "; break; }	//transform key to numbers
			}
		string endme[n];
		for (int i = 0; i < k; i++)
			endme[i] = "";

		for (int i = 0; i < k; i++) //for each substr
			for (int j = 0; j < substr[i].length(); j++)
			{
				for (int l = 0; l < n; l++)
				{
					if (substr[i][j] == strLC[l]) {   
						endme[i] += strLC[mod(l - keyint[i])];
						break;
					}
					 if (l + 1 == n)cout << "ACHTUNG!";
				}
			}

		output << "\n\n";
		for (int i = 0; i < k; i++)
		{
			output << endme[i] << "\n\n";
			//output << substr[i] << "\n\n";
		}

			//original text building
		controlstr = "";
		for (int j = 0; j < a; j++)
			for (int i = 0; i < k; i++)//check
			{
				if (endme[i][j] != '\0') controlstr += endme[i][j];
			}

		output << "\n\n\n" << controlstr << "\n\n";



	}

	
	
	input.close();
	output.close();
	inputee.close();
	outputee.close();
}

int main() {


	setlocale(LC_ALL, "Russian");

	copytext();
	

	system("pause");
	return 0;
}