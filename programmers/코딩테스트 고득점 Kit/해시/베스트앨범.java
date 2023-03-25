import java.util.*;
class Album {
    private int playCount;
    private int genre;
    private int uniqueNumber;
    Album(int playCount, int genre, int uniqueNumber) {
        this.playCount = playCount;
        this.genre = genre;
        this.uniqueNumber = uniqueNumber;
    }

    public int getPlayCount() {
        return playCount;
    }

    public int getGenre() {
        return genre;
    }

    public int getUniqueNumber() {
        return uniqueNumber;
    }
}

class Genres {
    private String name;
    private int playCount;

    public String getName() {
        return name;
    }

    public int getPlayCount() {
        return playCount;
    }

    public Genres(String name, int playCount) {
        this.name = name;
        this.playCount = playCount;
    }
}

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        List<Album> albumList = new ArrayList<>();
        Map<String, Integer> genrePlaySum = new HashMap<>();
        Map<String, Integer> genreRank = new HashMap<>();
        Map<Integer, Integer> genreCountInBestAlbum = new HashMap<>();

        //장르별 플레이수 합계
        for(int i=0;i<genres.length;i++) {
            if(genrePlaySum.containsKey(genres[i])) genrePlaySum.put(genres[i], genrePlaySum.get(genres[i]) + plays[i]);
            else genrePlaySum.put(genres[i], plays[i]);
            genreRank.put(genres[i], 0);
        }

        //장르별 순위 계산
        List<Genres> genresList = new ArrayList<>();
        for (String genre : genreRank.keySet()) {
            genresList.add(new Genres(genre, genrePlaySum.get(genre)));
        }
        genresList.sort(Comparator.comparing(Genres::getPlayCount).reversed());
        for(int i=0;i<genresList.size();i++) {
            genreRank.put(genresList.get(i).getName(), i+1);
            genreCountInBestAlbum.put(i+1, 0);
        }

        //리스트 만들기
        for(int i=0;i<genres.length;i++)
            albumList.add(new Album(10000-plays[i], genreRank.get(genres[i]), i));
        ArrayList<Integer> arrayList = new ArrayList<>();
        albumList.sort(Comparator.comparing(Album::getGenre).thenComparing(Album::getPlayCount).thenComparing(Album::getUniqueNumber));

        for(Album album : albumList) {
            if (genreCountInBestAlbum.get(album.getGenre()) == 2) continue;
            genreCountInBestAlbum.put(album.getGenre(), genreCountInBestAlbum.get(album.getGenre()) + 1);
            arrayList.add(album.getUniqueNumber());
        }
        int[] answer = new int[arrayList.size()];
        for(int i=0;i< arrayList.size();i++) {
            answer[i] = arrayList.get(i);
        }
        return answer;
    }
}