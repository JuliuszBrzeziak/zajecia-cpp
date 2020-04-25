from django.shortcuts import render
from . models import Wpis

# Create your views here.
def wpisy_list(reqest):
    wpis = Wpis.objects.all().order_by('date')
    return render(reqest,'wpisy/wpisy_list.html',{'artyk':wpis})
    