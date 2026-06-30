class Recording {
  final int? id;
  final int userId;
  final DateTime date;
  final String path;

  Recording({
    this.id,
    required this.userId,
    required this.date,
    required this.path,
  });

  Map<String, dynamic> toMap() {
    return {
      'id': id,
      'userId': userId,
      'date': date.toIso8601String(),
      'path': path,
    };
  }

  factory Recording.fromMap(Map<String, dynamic> map) {
    return Recording(
      id: map['id'] as int?,
      userId: map['userId'] as int,
      date: DateTime.parse(map['date'] as String),
      path: map['path'] as String,
    );
  }
}
