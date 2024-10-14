set pagination off

set $break_hit_count = 0

break range.c:28
command 1
    set $break_hit_count = $break_hit_count + 1
    if ($break_hit_count >= 28 && $break_hit_count <= 35)
        echo @@@
        print M
        echo @@@
        print N
        echo @@@
        print S
        echo @@@
        print i
    end
    continue
end

run -100 100 3 > /dev/null
quit
