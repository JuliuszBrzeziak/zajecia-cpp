from django.db import models

# Create your models here.
class Wpis(models.Model):
    title = models.CharField(max_length=100)
    slug = models.SlugField()
    body = models.TextField()
    date = models.DateTimeField(auto_now_add=True)
    #dodaj miniaturkę do wpisy
    #dodaj autora