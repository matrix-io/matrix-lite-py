# List of balena arm images https://www.balena.io/docs/reference/base-images/devicetypes/
FROM balenalib/raspberrypi3-debian-python:3.7.3-stretch-build

# Starting directory
WORKDIR /app
COPY . /app

# Grab latest Raspbian packages
RUN apt-get update

# Start compiling MATRIX Lite PY
CMD ["bash", "docker/packageCompile.sh"]