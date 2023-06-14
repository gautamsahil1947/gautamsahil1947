# must download pytube module using pip install
from pytube import YouTube, Playlist

outFileName = input("Enter output file name: ")
url = input("URL: ")

with open(outFileName, "w") as file:
    playlist = Playlist(url)
    for videourl in playlist:
        vidtitle = YouTube(videourl).title
        file.write(f"- [ ] [{vidtitle}]({videourl})\n")
