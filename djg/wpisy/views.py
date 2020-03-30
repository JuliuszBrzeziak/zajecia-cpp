from django.shortcuts import render

# Create your views here.
def wpisy_list(reqest):
    return render(reqest,'wpisy/wpisy_list.html')