use std::collections::HashMap;
use std::cmp;

fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();

    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    let songs: Vec<usize> = input
        .split_whitespace()
        .filter_map(|s| s.parse().ok())
        .collect();

    let mut song_indices = HashMap::new();
    let mut max_len = 0;
    let mut start_idx = 0;

    for (i, &song) in songs.iter().enumerate() {
        if let Some(&idx) = song_indices.get(&song) {
            start_idx = cmp::max(start_idx, idx + 1);
        }
        max_len = cmp::max(max_len, i - start_idx + 1);
        song_indices.insert(song, i);
    }

    println!("{}", max_len);
}
