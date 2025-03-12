#include <fstream>
#include <iomanip> /*serve per mettere manipolatori per stampare*/
#include <iostream>

double map(double x)
{
    double w;
    w = 0.75 * x - 1.75;
    return w;
}

double Nmean(double arr[], int n)
{
    int i = 0;
    double s = 0;
    for (i = 0; i < n; i++){
        s = s + arr[i];
    }
    s = s/n;
    return s;
}

void write(double arr[]){
    std::ofstream outfile("./result.txt");
    if (outfile.is_open()){
        outfile << "# N Mean \n";
        for (int i = 1; i<= 1000; i++){
            outfile << std::setprecision(16) << std::scientific;
            outfile << i << " " << Nmean(arr, i) << "\n";
        }
        outfile.close();
    }else{
        std::cout <<"Could not open the file" <<std::endl;
    }
}

int main()
{
    std::ifstream file("./data.txt"); /*apro il file*/
    if(file.fail())
    {
        std::cerr <<"Could not open the file"<<std::endl;
        return 1;
    }

    double val;
    int i = 0;
    double arr[1000];
    while(file >> val)
    {
        arr[i] = map(val);
        i++;
    }
    write(arr);
    return 0;
}   
