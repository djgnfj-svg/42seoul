minikube start --driver=virtualbox
eval $(minikube docker-env)

#metallb
minikube addons enable metallb
kubectl apply -f ./srcs/metallb/metallb.yaml

# nginx
cd ./srcs/nginx
echo "\033[32mnginx image build\033[0m"
docker build -t nginx:latest .	> /dev/null
echo "\033[36mnginx deployment\033[0m"
kubectl apply -f ./nginx-secret.yaml
kubectl apply -f ./nginx.yaml