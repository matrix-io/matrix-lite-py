# Deploy to PyPi With Docker
Auto deployment to [PyPi](https://pypi.org/project/matrix-lite/) is done through [TravisCI](https://travis-ci.org/).

The armv6l & armv7l images are used to compile for different Raspberry Pi devices.

Pushing a new tag with the format `v0.0.0` will trigger a build to compile all the Python packages for matrix-lite-py.

```bash
git tag v0.0.0
git push origin --tags
```
