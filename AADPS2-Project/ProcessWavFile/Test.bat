: Delete log files first.
cd OutCmp

del whiteNoise_Model0_vs_Model1_220.txt
del whiteNoise_Model0_vs_Model1_221.txt
del whiteNoise_Model0_vs_Model1_2201.txt
del whiteNoise_Model0_vs_Model1_200.txt

del whiteNoise_Model1_vs_Model2_220.txt
del whiteNoise_Model1_vs_Model2_221.txt
del whiteNoise_Model1_vs_Model2_2201.txt
del whiteNoise_Model1_vs_Model2_200.txt

del titanic_horn_Model0_vs_Model1_220.txt
del titanic_horn_Model0_vs_Model1_221.txt
del titanic_horn_Model0_vs_Model1_2201.txt
del titanic_horn_Model0_vs_Model1_200.txt

del titanic_horn_Model1_vs_Model2_220.txt
del titanic_horn_Model1_vs_Model2_221.txt
del titanic_horn_Model1_vs_Model2_2201.txt
del titanic_horn_Model1_vs_Model2_200.txt

cd ..

: Execute Model 0, Model 1, Model 2 and Model 3
cd Debug
ProcessWavFile.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\WhiteNoise.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel0_OM_221.wav" "1" "-6" "1" "0"
ProcessWavFile.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\WhiteNoise.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel0_OM_220.wav" "1" "-6" "0" "0"
ProcessWavFile.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\WhiteNoise.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel0_OM1_220.wav" "1" "-6" "0" "1"
ProcessWavFile.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\WhiteNoise.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel0_OM_200.wav" "0" "-6" "0" "1"


ProcessWavFile_model1.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\WhiteNoise.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel1_OM_221.wav" "1" "-6" "1" "0"
ProcessWavFile_model1.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\WhiteNoise.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel1_OM_220.wav" "1" "-6" "0" "0"
ProcessWavFile_model1.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\WhiteNoise.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel1_OM1_220.wav" "1" "-6" "0" "1"
ProcessWavFile_model1.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\WhiteNoise.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel1_OM_200.wav" "0" "-6" "0" "1"


ProcessWavFile_model2.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\WhiteNoise.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel2_OM_221.wav" "1" "-6" "1" "0"
ProcessWavFile_model2.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\WhiteNoise.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel2_OM_220.wav" "1" "-6" "0" "0"
ProcessWavFile_model2.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\WhiteNoise.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel2_OM1_220.wav" "1" "-6" "0" "1"
ProcessWavFile_model2.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\WhiteNoise.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel2_OM_200.wav" "0" "-6" "0" "1"

ProcessWavFile.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_horn.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel0_OM_221.wav" "1" "-6" "1" "0"
ProcessWavFile.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_horn.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel0_OM_220.wav" "1" "-6" "0" "0"
ProcessWavFile.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_horn.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel0_OM1_220.wav" "1" "-6" "0" "1"
ProcessWavFile.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_horn.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel0_OM_200.wav" "0" "-6" "0" "1"


ProcessWavFile_model1.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_horn.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel1_OM_221.wav" "1" "-6" "1" "0"
ProcessWavFile_model1.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_horn.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel1_OM_220.wav" "1" "-6" "0" "0"
ProcessWavFile_model1.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_horn.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel1_OM1_220.wav" "1" "-6" "0" "1"
ProcessWavFile_model1.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_horn.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel1_OM_200.wav" "0" "-6" "0" "1"


ProcessWavFile_model2.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_horn.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel2_OM_221.wav" "1" "-6" "1" "0"
ProcessWavFile_model2.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_horn.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel2_OM_220.wav" "1" "-6" "0" "0"
ProcessWavFile_model2.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_horn.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel2_OM1_220.wav" "1" "-6" "0" "1"
ProcessWavFile_model2.exe  "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_horn.wav" "C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel2_OM_200.wav" "0" "-6" "0" "1"

cd ..
cd tools
: Generate new logs
PCMCompare.exe C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel0_OM_221.wav C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel1_OM_221.wav 2>C:\Users\stevo\OneDrive\Desktop\AADSP2Projekat2021\Prjtemplates\ProcessWavFile\OutCmp\whiteNoise_Model0_vs_Model1_221.txt
PCMCompare.exe C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel0_OM_220.wav C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel1_OM_220.wav 2>C:\Users\stevo\OneDrive\Desktop\AADSP2Projekat2021\Prjtemplates\ProcessWavFile\OutCmp\whiteNoise_Model0_vs_Model1_220.txt
PCMCompare.exe C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel0_OM1_220.wav C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel1_OM1_220.wav 2>C:\Users\stevo\OneDrive\Desktop\AADSP2Projekat2021\Prjtemplates\ProcessWavFile\OutCmp\whiteNoise_Model0_vs_Model1_2201.txt
PCMCompare.exe C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel0_OM_200.wav C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel1_OM_200.wav 2>C:\Users\stevo\OneDrive\Desktop\AADSP2Projekat2021\Prjtemplates\ProcessWavFile\OutCmp\whiteNoise_Model0_vs_Model1_200.txt

PCMCompare.exe C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel1_OM_221.wav C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel2_OM_221.wav 2>C:\Users\stevo\OneDrive\Desktop\AADSP2Projekat2021\Prjtemplates\ProcessWavFile\OutCmp\whiteNoise_Model1_vs_Model2_221.txt
PCMCompare.exe C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel1_OM_220.wav C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel2_OM_220.wav 2>C:\Users\stevo\OneDrive\Desktop\AADSP2Projekat2021\Prjtemplates\ProcessWavFile\OutCmp\whiteNoise_Model1_vs_Model2_220.txt
PCMCompare.exe C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel1_OM1_220.wav C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel2_OM1_220.wav 2>C:\Users\stevo\OneDrive\Desktop\AADSP2Projekat2021\Prjtemplates\ProcessWavFile\OutCmp\whiteNoise_Model1_vs_Model2_2201.txt
PCMCompare.exe C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel1_OM_200.wav C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\outputModel2_OM_200.wav 2>C:\Users\stevo\OneDrive\Desktop\AADSP2Projekat2021\Prjtemplates\ProcessWavFile\OutCmp\whiteNoise_Model1_vs_Model2_200.txt

PCMCompare.exe C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel0_OM_221.wav C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel1_OM_221.wav 2>C:\Users\stevo\OneDrive\Desktop\AADSP2Projekat2021\Prjtemplates\ProcessWavFile\OutCmp\titanic_horn_Model0_vs_Model1_221.txt
PCMCompare.exe C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel0_OM_220.wav C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel1_OM_220.wav 2>C:\Users\stevo\OneDrive\Desktop\AADSP2Projekat2021\Prjtemplates\ProcessWavFile\OutCmp\titanic_horn_Model0_vs_Model1_220.txt
PCMCompare.exe C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel0_OM1_220.wav C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel1_OM1_220.wav 2>C:\Users\stevo\OneDrive\Desktop\AADSP2Projekat2021\Prjtemplates\ProcessWavFile\OutCmp\titanic_horn_Model0_vs_Model1_2201.txt
PCMCompare.exe C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel0_OM_200.wav C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel1_OM_200.wav 2>C:\Users\stevo\OneDrive\Desktop\AADSP2Projekat2021\Prjtemplates\ProcessWavFile\OutCmp\titanic_horn_Model0_vs_Model1_200.txt

PCMCompare.exe C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel1_OM_221.wav C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel2_OM_221.wav 2>C:\Users\stevo\OneDrive\Desktop\AADSP2Projekat2021\Prjtemplates\ProcessWavFile\OutCmp\titanic_horn_Model1_vs_Model2_221.txt
PCMCompare.exe C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel1_OM_220.wav C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel2_OM_220.wav 2>C:\Users\stevo\OneDrive\Desktop\AADSP2Projekat2021\Prjtemplates\ProcessWavFile\OutCmp\titanic_horn_Model1_vs_Model2_220.txt
PCMCompare.exe C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel1_OM1_220.wav C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel2_OM1_220.wav 2>C:\Users\stevo\OneDrive\Desktop\AADSP2Projekat2021\Prjtemplates\ProcessWavFile\OutCmp\titanic_horn_Model1_vs_Model2_2201.txt
PCMCompare.exe C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel1_OM_200.wav C:\Users\stevo\Downloads\Vezba3\postavka\TestStreams\titanic_hornoutputModel2_OM_200.wav 2>C:\Users\stevo\OneDrive\Desktop\AADSP2Projekat2021\Prjtemplates\ProcessWavFile\OutCmp\titanic_horn_Model1_vs_Model2_200.txt
