echo "processing output"
g++ edf_schedulling.cpp -o edf_schedulling.exe
./edf_schedulling.exe
echo "plotting graph"
python3 plot.py
