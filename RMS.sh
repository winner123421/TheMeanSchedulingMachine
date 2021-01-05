echo "processing output"
g++ rms_schedulling.cpp -o rms_schedulling.exe
./rms_schedulling.exe
echo "plotting graph"
python3 plot.py
