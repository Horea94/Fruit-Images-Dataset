# API of opencv-text-recognition

Python3.6 + OpenCV + Flask + CNN(ResNet)

## How to run it?

`
conda create -n py3 python=3
`

`
conda activate py3 
`

`
(py3) pip install -r requirements.txt
`

`
(py3) python api.py
`

### Verify it

`
curl --form "file=@/Users/yangboz/test/den_test_missing.jpg" -X POST 118.190.96.120:5000/iDentisty/API/predict
`

### Web Client test 

https://118.190.96.120:5000/iDentisty/API/client/index.html

## Reference 

