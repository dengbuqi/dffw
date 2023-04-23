
docker build -f dffw.dockrefile -t dffw .

# docker image rm -f $(docker images -a | grep -v "cca71b480a40" | awk 'NR>1 {print $3}')

docker run --name dffw_con --gpus all -d -it -v /home/deng/data/dffw:/root --gpus all --runtime=nvidia dffw # bash  --rm exit and remove

docker exec -it dffw_con bash
