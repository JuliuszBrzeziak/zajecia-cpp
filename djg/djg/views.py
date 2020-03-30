from django.http import HttpResponse
from django.shortcuts import render


def jeden(request):
    #return HttpResponse('jeden dwa')
    return render(request, 'jeden.html')



def mainn(request):
    #return HttpResponse('jeden dwa')
    return render(request, 'mainn.html')
