function solution(files) {
    files.sort((a, b) => {
        let pattern = /([0-9]{1,5})/
        a = a.toLowerCase().split(pattern)
        b = b.toLowerCase().split(pattern)
        let [aHead, aNum, aTail] = [a[0], parseInt(a[1]), a[2]]
        let [bHead, bNum, bTail] = [b[0], parseInt(b[1]), b[2]]
        return aHead == bHead ? aNum == bNum ? 1 : aNum > bNum ? 1 : -1 : aHead > bHead ? 1 : -1
    })
    return files;
}